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
//  Randomizer.cpp
//  Implementation of the Class Randomizer
//  Created on:      17-Jul-2009
//  Original author: ToddA
//
//  See Randomizer.h for description
//
///////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/model/Randomizer.h"
#include "com/themightystags/toddtris/model/Block.h"
#include <stdlib.h>

using com::themightystags::toddtris::model::Randomizer;
using com::themightystags::toddtris::model::SimpleRandomizer;
using com::themightystags::toddtris::model::AbstractTgmRandomizer;
using com::themightystags::toddtris::model::Tgm1Randomizer;
using com::themightystags::toddtris::model::Tgm2Randomizer;
using com::themightystags::toddtris::model::TtcRandomizer;
using com::themightystags::toddtris::model::Block;

Randomizer *Randomizer::newDefaultRandomizer() {
	return new Tgm1Randomizer();
}

Randomizer::Randomizer() {}

Randomizer::~Randomizer() {}

SimpleRandomizer::SimpleRandomizer() {}

SimpleRandomizer::~SimpleRandomizer() {}

void SimpleRandomizer::reset() {}

int SimpleRandomizer::getBlockNum() {
	return rand() % Block::NUM_BLOCKS;
}

AbstractTgmRandomizer::AbstractTgmRandomizer(int maxTries)
		: maxTries(maxTries), next(0) {}

AbstractTgmRandomizer::~AbstractTgmRandomizer() {}

void AbstractTgmRandomizer::reset() {
	// pre-fill the history as required by the subclass
	history.clear();
	prefillHistory();

	// choose a random first piece which is not S, Z or O
	vector<int> firstBlockBag;
	for (int i = 1; i <= Block::NUM_BLOCKS; ++i) {
		if (Block::O != i && Block::Z != i && Block::S != i) {
			firstBlockBag.push_back(i);
		}
	}
	int blockIndex = rand() % firstBlockBag.size();
	next = firstBlockBag.at(blockIndex);
}

bool AbstractTgmRandomizer::inHistory(const int blockNum) {
	deque<int>::iterator historyIter = history.begin();
	while (historyIter != history.end()) {
		if (*historyIter == blockNum) {
			return true;
		}
		++historyIter;
	}
	return false;
}

int AbstractTgmRandomizer::getBlockNum() {
	// remember the next block so we can return it
	int ret = next;
	// add the next block to the history
	historyPop();
	historyPush(next);
	// pick a new next block
	// retry up to maxTries times if the chosen block is in the history
	int tries = 0;
	do {
		next = rand() % Block::NUM_BLOCKS + 1;
	} while (tries++ < maxTries && inHistory(next));
	return ret;
}

void AbstractTgmRandomizer::historyPop() {
	history.pop_back();
}

void AbstractTgmRandomizer::historyPush(int blockNum) {
	history.push_front(blockNum);
}

Tgm1Randomizer::Tgm1Randomizer() : AbstractTgmRandomizer(4) {
	reset();
}
Tgm1Randomizer::~Tgm1Randomizer() {}

void Tgm1Randomizer::prefillHistory() {
	for (int i = 0; i < 4; ++i) {
		historyPush(Block::Z);
	}
}

Tgm2Randomizer::Tgm2Randomizer() : AbstractTgmRandomizer(6) {
	reset();
}
Tgm2Randomizer::~Tgm2Randomizer() {}

void Tgm2Randomizer::prefillHistory() {
	for (int i = 0; i < 4; ++i) {
		int blockNum = i % 2 ? Block::Z : Block::S;
		historyPush(blockNum);
	}
}

TtcRandomizer::TtcRandomizer() {
	reset();
}

TtcRandomizer::~TtcRandomizer() {}

void TtcRandomizer::reset() {
	sequence.clear();

	// create a bag of all the different blocks to pick from
	// also calculate the number of possible permutation of all our blocks
	vector<int> bag;
	int numPermutations = 1;
	for (int i = 1; i <= Block::NUM_BLOCKS; ++i) {
		bag.push_back(i);
		numPermutations *= i;
	}

	// now pick a permutation and work out the piece sequence
	int perm = rand() % numPermutations;
	for (int i = Block::NUM_BLOCKS; i > 0; --i) {
		int blockIndex = perm % i;
		perm = (perm - blockIndex) / i;
		int blockNum = bag.at(blockIndex);
		bag.erase(bag.begin() + blockIndex);
		sequence.push_back(blockNum);
	}

	// set the iterator to the start of the sequence
	sequenceIter = sequence.begin();
}

int TtcRandomizer::getBlockNum() {
	// get current value
	int ret = *sequenceIter;
	// prepare sequence for next call
	if (++sequenceIter == sequence.end()) {
		reset();
	}
	return ret;
}


