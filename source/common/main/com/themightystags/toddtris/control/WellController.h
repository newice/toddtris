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
//  WellController.h
//  Implementation of the Class WellController
//  Created on:      18-Nov-2008 18:56:42
//  Original author: ToddA
//
// The WellController class is used when the game is in a playing state to
// manipulate the players' wells.
//
// A WellController is created for each well and the PlayingState class
// delegates button presses to this.
//
// WellController will in delegate left, right and down button presses to
// 'repeater' classes.  The repeater classes are used to repeat a movement
// when the player holds a button down.
//
// The WellController and repeaters further delegate to an ActionHandler
// subclass which in turn manipulates the well.
//
// The point of the ActionHandler is that there is StillActionHandler for
// use when the game is paused and a MovingActionHandler for use when the
// game is in progress.  In practice this is not really required;
///////////////////////////////////////////////////////////

#if !defined(EA_8A997580_0590_4eac_8BDF_1D899245D39C__INCLUDED_)
#define EA_8A997580_0590_4eac_8BDF_1D899245D39C__INCLUDED_

#include "com/themightystags/toddtris/model/Well.h"
#include "com/themightystags/toddtris/model/WellListener.h"
#include "com/themightystags/toddtris/control/ActionHandler.h"
#include "com/themightystags/toddtris/control/Repeater.h"

using com::themightystags::toddtris::model::WellListener;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace control {

				class WellController: public WellListener {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					WellController(const WellController& object);
					WellController& operator=(const WellController& object);

				public:
					WellController(Well &well);
					virtual ~WellController();

					bool rotate();
					bool antirotate();
					void leftPressed();
					void leftHeld();
					void rightPressed();
					void rightHeld();
					void downPressed();
					void downHeld();
					bool drop();
					bool hold();
					void restart();
					void togglePause();
					void blockLanded(const Well &well);

				private:
					Well &well;
					ActionHandler &getHandler();
					LeftRepeater leftRepeater;
					RightRepeater rightRepeater;
					DownRepeater downRepeater;
					static const long DOWN_PAUSE_MS = 20;
					static const long LEFT_RIGHT_REPEAT_PAUSE_MS = 40;
					static const long LEFT_RIGHT_FIRST_PAUSE_MS =
							LEFT_RIGHT_REPEAT_PAUSE_MS * 3;
				};
			}
		}
	}
}
#endif // !defined(EA_8A997580_0590_4eac_8BDF_1D899245D39C__INCLUDED_)
