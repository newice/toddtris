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

#ifndef OnePlayerMenuState_H
#define OnePlayerMenuState_H

#include "com/themightystags/toddtris/app/MenuState.h"
#include "com/themightystags/toddtris/app/PlayerSettings.h"

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {

				class OnePlayerMenuState: public MenuState {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					OnePlayerMenuState(const OnePlayerMenuState& object);
					OnePlayerMenuState& operator=(const OnePlayerMenuState& object);

				public:
					OnePlayerMenuState(AppStateMachine &appStateMachine,
							const RendererFactory &rf);

					~OnePlayerMenuState();

					void upPressed(int controllerId);
					void downPressed(int controllerId);
					void leftPressed(int controllerId);
					void rightPressed(int controllerId);
					void onePressed(int controllerId);
					void twoPressed(int controllerId);
					void draw(bool full);

				private:
					enum OnePlayerMenuOption {Type, Level, Height, UpToDrop} selectedOption;
					PlayerSettings playerSettings;
				};
			}
		}
	}
}
#endif // OnePlayerMenuState
