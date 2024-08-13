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

using com::themightystags::toddtris::input::InputReader;

bool InputReader::initialised = false;

InputState InputReader::getInputState() {

	if (!initialised)
		init();

	InputState inputState = { { 0 } };

	// WPAD_ScanPads reads the latest controller states
	WPAD_ScanPads();

	for (int i = 0; i < InputState::NUM_INPUTS; ++i) {

		// WPAD_ButtonsDown tells us which buttons were pressed in this loop
		// this is a "one shot" state which will not fire again until the button has been released
		u32 pressed = WPAD_ButtonsDown(i);
		u32 held = WPAD_ButtonsHeld(i);
		u32 released = WPAD_ButtonsUp(i);

		// Check for down movement. Remember the wiimote is rotated
		inputState.downPressed[i] = (pressed & DOWN);
		inputState.downHeld[i] = (held & DOWN);
		inputState.downReleased[i] = (released & DOWN);

		// Check for up movement. Remember the wiimote is rotated
		inputState.upPressed[i] = (pressed & UP);
		inputState.upHeld[i] = (held & UP);
		inputState.upReleased[i] = (released & UP);

		// Check for left movement. Remember the wiimote is rotated
		inputState.leftPressed[i] = (pressed & LEFT);
		inputState.leftHeld[i] = (held & LEFT);
		inputState.leftReleased[i] = (released & LEFT);

		// Check for right movement. Remember the wiimote is rotated
		inputState.rightPressed[i] = (pressed & RIGHT);
		inputState.rightHeld[i] = (held & RIGHT);
		inputState.rightReleased[i] = (released & RIGHT);

		// Look for other key presses.
		inputState.rotatePressed[i] = (pressed & ROTATE);
		inputState.rotateHeld[i] = (held & ROTATE);
		inputState.antirotatePressed[i] = (pressed & ANTIROTATE);
		inputState.antirotateHeld[i] = (held & ANTIROTATE);
		inputState.ghostPressed[i] = (pressed & GHOST);
		inputState.ghostHeld[i] = (held & GHOST);
		inputState.holdPressed[i] = (pressed & HOLD);
		inputState.holdHeld[i] = (held & HOLD);
		inputState.pausePressed[i] = (pressed & PAUSE);
		inputState.pauseHeld[i] = (held & PAUSE);
		inputState.dropPressed[i] = (pressed & DROP);
		inputState.dropHeld[i] = (held & DROP);
//		uncomment to enable screenshots in where supported (Wii GX version)
//		inputState.screenshotPressed[i] = (pressed & SCREENSHOT);
//		inputState.screenshotHeld[i] = (held & SCREENSHOT);
	}
	return inputState;
}

void InputReader::init() {
	// This function initialises the attached controllers
	WPAD_Init();
	initialised = true;
}

