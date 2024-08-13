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

#ifndef GameStoppedState_H
#define GameStoppedState_H

#include "com/themightystags/toddtris/app/AppState.h"
#include "com/themightystags/util/Timer.h"

using com::themightystags::util::Timer;

namespace com {
	namespace themightystags {
		namespace toddtris {

			namespace app {

				class GameStoppedState : public AppState {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					GameStoppedState(const GameStoppedState& object);
					GameStoppedState& operator=(const GameStoppedState& object);

				public:
					GameStoppedState(AppStateMachine &appStateMachine,
							const RendererFactory &rf,
							const vector<string> options,
							bool freezeOnEntry);

					~GameStoppedState();

					void prepare();
					void upPressed(int controllerId);
					void downPressed(int controllerId);
					void onePressed(int controllerId);
					void twoPressed(int controllerId);
					void pausePressed(int controllerId);

				protected:
					void draw(bool full);
					virtual void draw(bool full,
							const vector<string> &options,
							int selectedIndex) = 0;
					virtual void optionSelected(string option) = 0;

				private:
					const vector<string> options;
					unsigned int selectedIndex;
					void optionSelected();

					// timer used to freeze the menu when the state is first
					// entered
					Timer freezeTimer;
					long freezeTime;
					static const long DEFAULT_FREEZE_TIME = 800;
				};
			}
		}
	}
}
#endif // GameStoppedState_H
