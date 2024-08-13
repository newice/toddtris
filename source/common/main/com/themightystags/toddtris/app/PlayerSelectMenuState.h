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

#ifndef PlayerSelectMenuState_H
#define PlayerSelectMenuState_H

#include "com/themightystags/toddtris/app/MenuState.h"

namespace com {
	namespace themightystags {
		namespace toddtris {

			namespace app {

				class PlayerSelectMenuState : public MenuState {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					PlayerSelectMenuState(const PlayerSelectMenuState& object);
					PlayerSelectMenuState& operator=(const PlayerSelectMenuState& object);

				public:
					PlayerSelectMenuState(AppStateMachine &appStateMachine,
							const RendererFactory &rf);

					~PlayerSelectMenuState();

					void upPressed(int controllerId);
					void downPressed(int controllerId);
					void twoPressed(int controllerId);
					void draw(bool full);

					void process();

				private:
					enum PlayerSelectMenuOption {OnePlayer, TwoPlayer, Exit} selectedOption;
				};
			}
		}
	}
}
#endif // PlayerSelectMenuState_H
