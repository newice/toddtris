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
//  TwoPlayerGame.cpp
//  Implementation of the Class TwoPlayerGame
//  Original author: ToddA
//
//  See TwoPlayerGame.h for description
///////////////////////////////////////////////////////////
#include "com/themightystags/toddtris/model/TwoPlayerGame.h"

#include <cstdlib>

using com::themightystags::toddtris::model::TwoPlayerGame;
using com::themightystags::toddtris::model::Well;

using namespace std;

TwoPlayerGame::TwoPlayerGame(Well &w0, Well &w1) :
		well0(w0),
		well1(w1),
		linesOwing(0),
		blankCol(rand() % Well::WELL_WIDTH) {

	scores[0] = 0;
	scores[1] = 0;
	well0.addListener(*this);
	well1.addListener(*this);
}

TwoPlayerGame::~TwoPlayerGame() {}

int TwoPlayerGame::getScore(unsigned int playerIndex) const {
	return (playerIndex < 2) ? scores[playerIndex] : -1;
}


void TwoPlayerGame::madeLines(const Well &well, int linesMade) {
	// if the player scored a tetris add all four of the lines made,
	// otherwise add one fewer
	int addLines = (linesMade == 4) ? linesMade : linesMade - 1;
	if (&well == &well0) {
		linesOwing += addLines;
	} else {
		linesOwing -= addLines;
	}
}

void TwoPlayerGame::pause() {
	well0.stopWell();
	well1.stopWell();
}

void TwoPlayerGame::resume() {
	well0.startWell();
	well1.startWell();
}



void TwoPlayerGame::newGame() {
	scores[0] = 0;
	scores[1] = 0;
	playAgain();
}


void TwoPlayerGame::playAgain() {
	well0.reset();
	well1.reset();
	well0.startWell();
	well1.startWell();
}

void TwoPlayerGame::gameOver(const Well &well) {
	int winner = &well == &well0 ? 1 : 0;
	++scores[winner];
	well0.stopWell();
	well1.stopWell();
	linesOwing = 0;
	blankCol = rand() % Well::WELL_WIDTH;
}

void TwoPlayerGame::wellReset(const Well &well) {
	linesOwing = 0;
	blankCol = rand() % Well::WELL_WIDTH;
}

void TwoPlayerGame::blockLanded(const Well &well) {
	if (&well == &well0) {
		while (linesOwing < 0) {
			well0.addLine(blankCol);
			linesOwing++;
		}
	} else {
		while (linesOwing > 0) {
			well1.addLine(blankCol);
			linesOwing--;
		}
	}
}
