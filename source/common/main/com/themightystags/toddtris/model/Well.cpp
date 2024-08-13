//    Copyright 2009 - 2012 Toddy
//
//    This file is part of Toddtris.
//
//    Toddtris is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    Toddtris is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Toddtris.  If not, see <http://www.gnu.org/licenses/>.

///////////////////////////////////////////////////////////
//  Well.cpp
//  Implementation of the Class Well
//  Created on:      07-Nov-2008 19:19:13
//  Original author: ToddA
//
//  See Well.h for detailed description
//
///////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/model/Well.h"
#include "com/themightystags/toddtris/model/KickOffset.h"
#include <stdlib.h>
#include <math.h>


using com::themightystags::toddtris::model::Well;
using com::themightystags::toddtris::model::Block;
using com::themightystags::toddtris::model::Randomizer;
using com::themightystags::toddtris::model::KickOffset;
using namespace std;

Block **Well::refBlockList = Well::createBlockList();

Well::Well(int targetLines, int startHeight, int level, bool useKicks) :
	block(0), targetLines(targetLines), level(level), useKicks(useKicks) {

	blockList = Well::createBlockList();
	randomizer = Randomizer::newDefaultRandomizer();
	setStartHeight(startHeight);
	reset();
}

Well::~Well() {
	for (int i = 0; i < Block::NUM_BLOCKS; ++i) {
		delete blockList[i];
	}
	delete[] blockList;
	delete randomizer;
}

void Well::setStartHeight(int sh) {
	if (sh < 0) {
		sh = 0;
	}
	if (sh > WELL_HEIGHT) {
		sh = WELL_HEIGHT;
	}
	startHeight = sh;
}

void Well::reset() {

	for (int i = 0; i < WELL_WIDTH; i++) {
		for (int j = 0; j < FULL_WELL_HEIGHT; j++) {
			deadElems[i][j] = 0;
		}
	}

	/* choose indices for the current and next block */
	randomizer->reset();
	nextBlockNum = getRandomBlockNum();

	/* no hold block */
	holdBlockNum = -1;
	holdAllowed = true;

	newBlock();

	lines = 0;

	wellState = newlyReset;

	/*
	 * Create the random blocks at the bottom of the well.
	 * Set one in three spaces in these rows to be contain blocks.
	 */
	for (int i = 1; i <= startHeight; i++) {
		for (int j = 0; j < WELL_WIDTH; j++) {
			if ((rand() % 3) == 0) {
				deadElems[j][FULL_WELL_HEIGHT - i] = -1 - Block::NUM_BLOCKS;
			}
		}
	}

	timer.reset();
	timer.setTimeout(400);

	listenerList.wellReset(*this);

}

void Well::updateChallengeSettings(int targetLines, int startHeight, int level) {
	Well::targetLines = targetLines;
	Well::level = level;
	setStartHeight(startHeight);
}

int Well::getTargetLines() const {
	return targetLines;
}

int Well::getLevel() const {
	return level;
}

void Well::addListener(WellListener &listener) {
	listenerList.addListener(listener);
}

/**
 * Can't start well not in progress
 */
void Well::startWell() {
	if (wellState == stopped || wellState == newlyReset) {
		wellState = playing;
		// unpause the timer if it was paused
		timer.unPause();
	}
}

void Well::stopWell() {
	if (wellState == playing) {
		wellState = stopped;
	}
	timer.pause();
}

/**
 * @return The amount of time the well has been running for. This does not include
 * any time when the well was stopped.
 */
int Well::getRunningTimeInSeconds() const {
	return timer.getElapsedMilliseconds() / 1000;
}

/**
 * @return bool
 */
bool Well::isComplete() const {
	return ((this->targetLines > 0) && (this->getLines() >= this->targetLines));
}

/**
 * @return bool
 */
bool Well::isMoving() const {
	return (wellState == playing);
}

/**
 * @return bool
 */
bool Well::isGameOver() const {
	return (wellState == gameOver);
}

/**
 * Gets the element in the position indicated ignoring the hidden lines
 * @return int
 */
int Well::getElem(int viewX, int viewY) const {

	int x = viewX;
	int y = viewY + HIDDEN_ROWS;

	/*
	 * copy the members into temporary variable to avoid any multithreading
	 * problems (not multithreaded at present anyway..)
	 */
	int tempBlockX = blockX;
	int tempBlockY = blockY;
	int tempGhostY = ghostY;
	Block *tempBlock = block;

	int blockSize = tempBlock->getSize();
	if ((x >= tempBlockX) && (y >= tempBlockY)
			&& (x < (tempBlockX + blockSize)) && (y < (tempBlockY + blockSize))) {

		/* This is within the blockArea */
		int blockElem = tempBlock->getElem(x - tempBlockX, y - tempBlockY);

		/*
		 * if this block element is greater than zero then return this
		 * number, otherwise just let this fall through to return a ghost
		 * element or the space in this position of deadElems
		 */
		if (blockElem > 0) {
			return blockElem;
		}
	}

	if ((x >= tempBlockX) && (y >= tempGhostY)
			&& (x < (tempBlockX + blockSize)) && (y < (tempGhostY + blockSize))) {

		/* This is within the blockArea */
		int blockElem = tempBlock->getElem(x - tempBlockX, y - tempGhostY);

		/*
		 * if this ghost block element is greater than zero then return this
		 * number, otherwise just let this fall through to return the space
		 * in this position of deadElems
		 */
		if (blockElem > 0) {
			return Block::NUM_BLOCKS + blockElem;
		}
	}

	return deadElems[x][y];
}

/**
 * @return int
 */
int Well::getLines() const {

	return lines;
}

/**
 * Only makes sense when a target has been set.
 * @return the number of remaining lines, or simply 0 if no target is set
 */
int Well::getRemainingLines() const {
	return (this->getTargetLines() == 0) ? 0 : this->isComplete() ? 0 //don't give a -ve
			: this->getTargetLines() - this->getLines(); //remaining lines
}

/**
 * @return com.themightystags.toddtris.model.Block
 */
const Block &Well::getNextBlock() const {
	Block *nb = Well::refBlockList[nextBlockNum - 1]; // blocks are numbered from 1
	return *nb;
}

const Block *Well::getHoldBlock() const {
	if (holdBlockNum >= 1) {
		Block *hb = Well::refBlockList[holdBlockNum - 1]; // blocks are numbered from 1
		return hb;
	} else {
		return NULL;
	}
}

int Well::getStartHeight() const {
	return startHeight;
}

/**
 * @return bool
 */
bool Well::left() {
	if (checkEmpty(*block, blockX - 1, blockY)) {
		blockX--;
		wellChanged();
		return true;
	} else {
		return false;
	}
}

/**
 * @return bool
 */
bool Well::right() {
	if (checkEmpty(*block, blockX + 1, blockY)) {
		blockX++;
		wellChanged();
		return true;
	} else {
		return false;
	}
}

/**
 * @return bool
 */
bool Well::rotate() {
	block->rotate();
	if (checkEmpty(*block, blockX, blockY)) {
		wellChanged();
		return true;
	} else {
		// if kicks are enabled then see if we can use a kick to fit the block
		if (this->useKicks) {
			for (int i = 0; i < block->getNumKickOffsets(); ++i) {
				const KickOffset &offset = block->getKickOffsetRotate(i);
				if (checkEmpty(*block, blockX + offset.getX(), blockY + offset.getY())) {
					blockX += offset.getX();
					blockY += offset.getY();
					wellChanged();
					return true;
				}
			}
		}

		// have not found a place for the block so undo the rotation
		block->antirotate();
		return false;
	}
}

/**
 * @return bool
 */
bool Well::antirotate() {
	block->antirotate();
	if (checkEmpty(*block, blockX, blockY)) {
		wellChanged();
		return true;
	} else {
		// if kicks are enabled then see if we can use a kick to fit the block
		if (this->useKicks) {
			for (int i = 0; i < block->getNumKickOffsets(); ++i) {
				const KickOffset &offset = block->getKickOffsetAntirotate(i);
				if (checkEmpty(*block, blockX + offset.getX(), blockY + offset.getY())) {
					blockX += offset.getX();
					blockY += offset.getY();
					wellChanged();
					return true;
				}
			}
		}

		// have not found a place for the block so undo the 'antirotation'
		block->rotate();
		return false;
	}
}

/**
 * @return true if not game over
 */
bool Well::down() {
	// calculate time to next automatic down movement
	static const int A = 450; // timeout when lines = 0
	static const double X = 2.1;
	static const int Y = 2000000;
	int timeout = int( Y / ((Y/A) + pow(double(lines + level * 10), X)) );
	timeout = (timeout > 10 ) ? timeout : 10;
	timer.setTimeout(timeout);
	if (blockDown()) {
		wellChanged();
		return true;
	} else {
		return landBlock();
	}
}

/**
 * @return bool
 */
bool Well::drop() {
	while (blockDown()) {
		// do nothing
	}
	return landBlock();
}

/**
 * @return bool
 */
bool Well::hold() {
	if (holdAllowed) {

		// The block we replace our block with will depend
		// on whether we already have a hold block
		int replaceBlockIndex;
		if (holdBlockNum >= 0) {
			// use previous hold block
			replaceBlockIndex = holdBlockNum;
		} else {
			// use the next block
			replaceBlockIndex = nextBlockNum;
			// set choose a new next block
			nextBlockNum = Well::getRandomBlockNum();
		}

		// set new hold block to be the current block
		holdBlockNum = block->getBlockNum();

		// Use the replacement block
		// It is possible that this could cause a game over
		setBlock(replaceBlockIndex);

		// prevent user from using hold again until this piece has been landed
		holdAllowed = false;

		// well has changed
		wellChanged();

		// use of hold was allowed
		return true;
	} else {

		// use of hold was not allowed
		return false;
	}
}

/**
 * @return bool
 */
bool Well::blockDown() {
	if (checkEmpty(*block, blockX, blockY + 1)) {
		blockY++;
		return true;
	} else {
		return false;
	}
}

/**
 * @return true if block safely landed, false if this is game over
 */
bool Well::landBlock() {
	putDeadBlock();

	int linesMade = checkLines();
	incLines(linesMade);

	bool ret;

	/* try and get a new block, returns false if there is not room (i.e. game over) */
	if (newBlock()) {

		listenerList.blockLanded(*this);
		ret = true;

	} else {

		/* game over */
		setGameOverState();
		listenerList.blockLanded(*this);
		ret = false;
	}

	if (linesMade > 0) {
		listenerList.madeLines(*this, linesMade);
	}
	// just landed a piece, so hold should be enabled if it had been blocked
	holdAllowed = true;

	wellChanged();
	return ret;
}

void Well::setGameOverState() {
	wellState = gameOver;
	timer.pause();
	listenerList.gameOver(*this);
}

/**
 * @return bool
 */
bool Well::checkEmpty(const Block &b, int x, int y) const {
	for (int i = 0; i < b.getSize(); i++) {
		for (int j = 0; j < b.getSize(); j++) {
			if ((b.getElem(i, j) != 0) && ((x + i < 0) || (x + i >= WELL_WIDTH)
					|| (y + j < 0) || (y + j >= FULL_WELL_HEIGHT)
					|| (deadElems[x + i][y + j] < 0))) {

				return false;
			}
		}
	}
	return true;
}

void Well::putDeadBlock() {
	for (int i = 0; i < block->getSize(); i++) {
		for (int j = 0; j < block->getSize(); j++) {
			if (block->getElem(i, j) != 0) {

				deadElems[blockX + i][blockY + j] = 0 - block->getElem(i, j);
			}
		}
	}
}

void Well::removeLine(int l) {
	for (int j = l; j > 0; j--) {
		for (int i = 0; i < WELL_WIDTH; i++) {
			deadElems[i][j] = deadElems[i][j - 1];
		}
	}
	for (int i = 0; i < WELL_WIDTH; i++) {
		deadElems[i][0] = 0;
	}
}

/**
 * @return bool
 */
bool Well::lineFull(int l) const {
	for (int i = 0; i < WELL_WIDTH; i++) {
		if (deadElems[i][l] == 0) {
			return false;
		}
	}
	return true;
}

/**
 * Get the height of the stack. This is the height of the highest block.
 * @return height of highest block as a number of rows.
 */
int Well::getStackHeight() const {
	int j;
	for (j = 0; j < WELL_HEIGHT; j++) {
		for (int i = 0; i < WELL_WIDTH; i++) {
			if (deadElems[i][j + HIDDEN_ROWS] < 0) {
				return j;
			}
		}
	}
	return WELL_HEIGHT - j;
}

/**
 * @return int
 */
int Well::checkLines() {
	int linesMade = 0;
	for (int j = 0; j < FULL_WELL_HEIGHT; j++) {
		if (lineFull(j)) {
			removeLine(j);
			linesMade++;
		}
	}
	return linesMade;
}

void Well::incLines(int l) {
	lines += l;

	/* see if the challenge has been completed */
	if (isComplete()) {
		wellState = complete;
		timer.pause();
		wellChanged();
		listenerList.complete(*this);
	}
}

/**
 * @return bool
 */
bool Well::newBlock() {
	bool ret = setBlock(nextBlockNum);
	nextBlockNum = Well::getRandomBlockNum();
	return ret;
}

/**
 * @return bool
 */
bool Well::setBlock(int blockNum) {

	/* reset the current block */
	if (block) {
		block->reset();
	}

	/* assign the new block */
	block = blockList[blockNum - 1]; // blocks are numbered from 1
	blockX = (WELL_WIDTH - block->getSize()) / 2;
	blockY = 4 - block->getSize();

	return checkEmpty(*block, blockX, blockY);
}

void Well::addLine(int blankCol) {
	for (int j = 1; j < FULL_WELL_HEIGHT; j++) {
		for (int i = 0; i < WELL_WIDTH; i++) {
			deadElems[i][j - 1] = deadElems[i][j];

		}
	}
	for (int i = 0; i < WELL_WIDTH; i++) {
		deadElems[i][FULL_WELL_HEIGHT - 1] = -1 - Block::NUM_BLOCKS;
	}
	deadElems[blankCol][FULL_WELL_HEIGHT - 1] = 0;
}

int Well::getRandomBlockNum() {
	return randomizer->getBlockNum();
}

Block **Well::createBlockList() {
	Block **ret = new Block*[Block::NUM_BLOCKS];
	for (int i = 0; i < Block::NUM_BLOCKS; ++i) {
		ret[i] = new Block(i + 1); // blocks are numbered from 1
	}
	return ret;
}

void Well::process() {
	if (timer.isTimeoutReached()) {
		down();
	}
}

void Well::wellChanged() {
	int y = blockY;
	while (true) {
		++y;
		if (!checkEmpty(*block, blockX, y)) {
			ghostY = y - 1;
			listenerList.wellChanged(*this);
			return;
		}
	}
	// should never get here
	throw "failed to find ghost location";
}

