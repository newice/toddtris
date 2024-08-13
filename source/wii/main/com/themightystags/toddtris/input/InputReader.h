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

// Class automatically generated by Dev-C++ New Class wizard

#ifndef INPUTREADER_H
#define INPUTREADER_H

#include "com/themightystags/toddtris/input/InputState.h"
#include <wiiuse/wpad.h>

using com::themightystags::toddtris::input::InputState;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace input {
				class InputReader {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					InputReader(const InputReader& object);
					InputReader& operator=(const InputReader& object);

				public:
					static InputState getInputState();

				private:
					static bool initialised;
					static void init();

					// button presses we look for
					static const u32 UP 		= WPAD_BUTTON_RIGHT | WPAD_CLASSIC_BUTTON_UP;
					static const u32 DOWN		= WPAD_BUTTON_LEFT | WPAD_CLASSIC_BUTTON_DOWN;
					static const u32 LEFT 		= WPAD_BUTTON_UP | WPAD_CLASSIC_BUTTON_LEFT;
					static const u32 RIGHT		= WPAD_BUTTON_DOWN | WPAD_CLASSIC_BUTTON_RIGHT;
					static const u32 ROTATE		= WPAD_BUTTON_2 | WPAD_CLASSIC_BUTTON_A;
					static const u32 ANTIROTATE	= WPAD_BUTTON_1 | WPAD_CLASSIC_BUTTON_B;
					static const u32 GHOST		= WPAD_BUTTON_PLUS | WPAD_CLASSIC_BUTTON_X;
					static const u32 HOLD		= WPAD_BUTTON_MINUS | WPAD_CLASSIC_BUTTON_Y;
					static const u32 PAUSE		= WPAD_BUTTON_HOME
													| WPAD_CLASSIC_BUTTON_MINUS | WPAD_CLASSIC_BUTTON_HOME
													| WPAD_CLASSIC_BUTTON_PLUS;
					static const u32 DROP		= WPAD_BUTTON_A
													| WPAD_CLASSIC_BUTTON_FULL_R | WPAD_CLASSIC_BUTTON_ZR
													| WPAD_CLASSIC_BUTTON_FULL_L | WPAD_CLASSIC_BUTTON_ZL;

					static const u32 SCREENSHOT	= WPAD_BUTTON_B;
				};
			}
		}
	}
}
#endif // INPUTREADER_H
