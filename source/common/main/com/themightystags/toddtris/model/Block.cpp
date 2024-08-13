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
//  Block.cpp
//  Implementation of the Class Block
//  Created on:      07-Nov-2008 19:17:57
//  Original author: ToddA
//
//  See Block.h for detailed description
//
///////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/model/Block.h"

using com::themightystags::toddtris::model::Block;

Block::Block(int blockNum) :
	blockNum(blockNum), rotationIndex(0) {
}

Block::~Block() {
	// nothing to do
}

int Block::ALL_ELEMS[NUM_ORIENTATIONS][NUM_BLOCKS][MAX_BLOCK_SIZE][MAX_BLOCK_SIZE] = {
				{ { { 0 } } } };

const int Block::BLOCK_SIZES[NUM_BLOCKS] = { 2, 3, 3, 3, 4, 3, 3 };

const KickOffset Block::DUMMY_KICK_OFFSET(0,0);

// Note: looking at the code below will show the blocks reflected diagonally
const int Block::BASE_ELEMS[NUM_BLOCKS][MAX_BLOCK_SIZE][MAX_BLOCK_SIZE]
		= {
			{
				{ O, O },
				{ O, O }
			},
			{
				{ X, T, X },
				{ T, T, X },
				{ X, T, X }
			},
			{
				{ X, L, X },
				{ X, L, X },
				{ L, L, X }
			},
			{
				{ J, J, X },
				{ X, J, X },
				{ X, J,	X }
			},
			{
				{ X, I, X, X },
				{ X, I, X, X },
				{ X, I, X, X },
				{ X, I, X, X }
			},
			{
				{ X, S, X },
				{ S, S, X },
				{ S, X, X }
			},
			{
				{ Z, X, X },
				{ Z, Z, X },
				{ X, Z, X }
			}
		};

const int Block::INITIALIZED = Block::initAllElems();

//
// Kick offset data taken from http://harddrop.com/wiki/SRS
// Note though that the Y offsets have to be inverted as the Y coordinates of the well start from 0 at the top
// Note that the first index in the KickOffset arrays denotes the orientation we are rotating into, NOT the one we are coming from
//
const KickOffset *Block::KICK_OFFSETS_I_ROTATE[NUM_ORIENTATIONS][NUM_KICK_OFFSETS_I]
		= {
				{new KickOffset(+1, 0), new KickOffset(-2, 0), new KickOffset(+1, +2), new KickOffset(-2, -1)}, // L -> 0
				{new KickOffset(-2, 0), new KickOffset(+1, 0), new KickOffset(-2, +1), new KickOffset(+1, -2)}, // 0 -> R
				{new KickOffset(-1, 0), new KickOffset(+2, 0), new KickOffset(-1, -2), new KickOffset(+2, +1)}, // R -> 2
				{new KickOffset(+2, 0), new KickOffset(-1, 0), new KickOffset(+2, -1), new KickOffset(-1, +2)}  // 2 -> L
		};

const KickOffset *Block::KICK_OFFSETS_I_ANTIROTATE[NUM_ORIENTATIONS][NUM_KICK_OFFSETS_I]
		= {
				{new KickOffset(+2, 0), new KickOffset(-1, 0), new KickOffset(+2, -1), new KickOffset(-1, +2)}, // R -> 0
				{new KickOffset(+1, 0), new KickOffset(-2, 0), new KickOffset(+1, +2), new KickOffset(-2, -1)}, // 2 -> R
				{new KickOffset(-2, 0), new KickOffset(+1, 0), new KickOffset(-2, +1), new KickOffset(+1, -2)}, // L -> 2
				{new KickOffset(-1, 0), new KickOffset(+2, 0), new KickOffset(-1, -2), new KickOffset(+2, +1)}  // 0 -> L
		};

const KickOffset *Block::KICK_OFFSETS_OTHER_ROTATE[NUM_ORIENTATIONS][NUM_KICK_OFFSETS_OTHER]
		= {
				{new KickOffset(-1, 0), new KickOffset(-1, +1), new KickOffset(0, -2), new KickOffset(-1, -2)}, // L -> 0
				{new KickOffset(-1, 0), new KickOffset(-1, -1), new KickOffset(0, +2), new KickOffset(-1, +2)}, // 0 -> R
				{new KickOffset(+1, 0), new KickOffset(+1, +1), new KickOffset(0, -2), new KickOffset(+1, -2)}, // R -> 2
				{new KickOffset(+1, 0), new KickOffset(+1, -1), new KickOffset(0, +2), new KickOffset(+1, +2)}  // 2 -> L
		};

const KickOffset *Block::KICK_OFFSETS_OTHER_ANTIROTATE[NUM_ORIENTATIONS][NUM_KICK_OFFSETS_OTHER]
		= {
				{new KickOffset(+1, 0), new KickOffset(+1, +1), new KickOffset(0, -2), new KickOffset(+1, -2)}, // R -> 0
				{new KickOffset(-1, 0), new KickOffset(-1, -1), new KickOffset(0, +2), new KickOffset(-1, +2)}, // 2 -> R
				{new KickOffset(-1, 0), new KickOffset(-1, +1), new KickOffset(0, -2), new KickOffset(-1, -2)}, // L -> 2
				{new KickOffset(+1, 0), new KickOffset(+1, -1), new KickOffset(0, +2), new KickOffset(+1, +2)}  // 0 -> L
		};

/**
 * @return int[][]
 */
void Block::rotateElems(const int(&source)[MAX_BLOCK_SIZE][MAX_BLOCK_SIZE],
		int(&target)[MAX_BLOCK_SIZE][MAX_BLOCK_SIZE], int blockSize) {

	for (int i = 0; i < blockSize; ++i) {
		for (int j = 0; j < blockSize; ++j) {
			target[blockSize - 1 - j][i] = source[i][j];
		}
	}
}

/**
 * @return int[][]
 */
void Block::copyElems(const int(&source)[MAX_BLOCK_SIZE][MAX_BLOCK_SIZE],
		int(&target)[MAX_BLOCK_SIZE][MAX_BLOCK_SIZE], int blockSize) {

	for (int i = 0; i < blockSize; ++i) {
		for (int j = 0; j < blockSize; ++j) {
			target[i][j] = source[i][j];
		}
	}
}

int Block::initAllElems() {
	for (int blockIndex = 0; blockIndex < NUM_BLOCKS; ++blockIndex) {
		int blockSize = BLOCK_SIZES[blockIndex];
		copyElems(BASE_ELEMS[blockIndex], ALL_ELEMS[0][blockIndex], blockSize);
		for (int rotationIndex = 1; rotationIndex <= 3; ++rotationIndex) {
			rotateElems(ALL_ELEMS[rotationIndex - 1][blockIndex],
					ALL_ELEMS[rotationIndex][blockIndex], blockSize);
		}
	}
	return 1;
}

/**
 * @return int
 */
int Block::getSize() const {
	return BLOCK_SIZES[blockNum - 1]; // blocks are numbered from 1
}

/**
 * @return int
 */
int Block::getElem(int x, int y) const {
	return ALL_ELEMS[rotationIndex][blockNum - 1][x][y]; // blocks are numbered from 1
}

void Block::rotate() {
	rotationIndex = (rotationIndex + 1) % 4;
}

void Block::antirotate() {
	rotationIndex = (rotationIndex + 3) % 4;
}

void Block::reset() {
	rotationIndex = 0;
}

/**
 * @return int
 */
int Block::getBlockNum() const {
	return blockNum;
}

/**
 * @return int
 */
int Block::getRotationIndex() const {
	return rotationIndex;
}

int Block::getNumKickOffsets() const {
	if (O == blockNum) {
		return 0; // no kicks for the 'O' piece
	} else if (I == blockNum) {
		return NUM_KICK_OFFSETS_I;
	} else {
		return NUM_KICK_OFFSETS_OTHER;
	}
}

const KickOffset &Block::getKickOffsetRotate(int kickIndex) const {
	if (O == blockNum) {
		return DUMMY_KICK_OFFSET; // should never get here
	} else if (I == blockNum) {
		return *(KICK_OFFSETS_I_ROTATE[rotationIndex][kickIndex]);
	} else {
		return *(KICK_OFFSETS_OTHER_ROTATE[rotationIndex][kickIndex]);
	}
}

const KickOffset &Block::getKickOffsetAntirotate(int kickIndex) const {
	if (O == blockNum ) {
		return DUMMY_KICK_OFFSET; // should never get here
	} else if (I == blockNum) {
		return *(KICK_OFFSETS_I_ANTIROTATE[rotationIndex][kickIndex]);
	} else {
		return *(KICK_OFFSETS_OTHER_ANTIROTATE[rotationIndex][kickIndex]);
	}
}

