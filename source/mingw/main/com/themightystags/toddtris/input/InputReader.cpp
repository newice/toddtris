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

#include "com/themightystags/toddtris/input/InputReader.h"
#include <windows.h>
#include <conio.h>

using namespace std;
using com::themightystags::toddtris::input::InputReader;

bool InputReader::initialised = false;

char InputReader::leftKeys[InputState::NUM_INPUTS]        = {'A', 'H'};
char InputReader::rightKeys[InputState::NUM_INPUTS]       = {'D', 'K'};
char InputReader::upKeys[InputState::NUM_INPUTS]          = {'W', 'U'};
char InputReader::downKeys[InputState::NUM_INPUTS]        = {'S', 'J'};
char InputReader::rotateKeys[InputState::NUM_INPUTS]      = {'T', 'P'};
char InputReader::antirotateKeys[InputState::NUM_INPUTS]  = {'F', 'L'};
char InputReader::pauseKeys[InputState::NUM_INPUTS]       = {'1', '2'};
char InputReader::ghostKeys[InputState::NUM_INPUTS]       = {'Q', 'Y'};
char InputReader::holdKeys[InputState::NUM_INPUTS]        = {'E', 'I'};
char InputReader::dropKeys[InputState::NUM_INPUTS]        = {'X', 'M'};

InputState InputReader::lastState = {{0}};

InputState InputReader::getInputState() {

	InputState inputState = {{0}};

	setInputState(inputState.leftPressed, inputState.leftHeld,
			lastState.leftPressed, lastState.leftHeld,
			leftKeys);

	setInputState(inputState.rightPressed, inputState.rightHeld,
			lastState.rightPressed, lastState.rightHeld,
			rightKeys);

	setInputState(inputState.upPressed, inputState.upHeld,
			lastState.upPressed, lastState.upHeld,
			upKeys);

	setInputState(inputState.downPressed, inputState.downHeld,
			lastState.downPressed, lastState.downHeld,
			downKeys);

	setInputState(inputState.rotatePressed, inputState.rotateHeld,
			lastState.rotatePressed, lastState.rotateHeld,
			rotateKeys);

	setInputState(inputState.antirotatePressed, inputState.antirotateHeld,
			lastState.antirotatePressed, lastState.antirotateHeld,
			antirotateKeys);

	setInputState(inputState.pausePressed, inputState.pauseHeld,
			lastState.pausePressed, lastState.pauseHeld,
			pauseKeys);

	setInputState(inputState.ghostPressed, inputState.ghostHeld,
			lastState.ghostPressed, lastState.ghostHeld,
			ghostKeys);

	setInputState(inputState.holdPressed, inputState.holdHeld,
			lastState.holdPressed, lastState.holdHeld,
			holdKeys);

	setInputState(inputState.dropPressed, inputState.dropHeld,
			lastState.dropPressed, lastState.dropHeld,
			dropKeys);

	lastState = inputState;

	// consume any key presses so these aren't dumped to the console when we
	// exit the game
	if (kbhit()) {
		getch();
	}

	return inputState;
}

void InputReader::setInputState(bool pressed[InputState::NUM_INPUTS],
		bool held[InputState::NUM_INPUTS],
		bool lastPressed[InputState::NUM_INPUTS],
		bool lastHeld[InputState::NUM_INPUTS],
		char keys[InputState::NUM_INPUTS]) {

	for (int i = 0; i < InputState::NUM_INPUTS; ++i) {
		if (GetAsyncKeyState(keys[i])) {
			held[i] = lastPressed[i] || lastHeld[i];
			pressed[i] = !held[i];
		}
	}
}

void InputReader::init() {
        // nothing to do
}

