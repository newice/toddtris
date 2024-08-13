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

#ifndef PlayingState_H
#define PlayingState_H

#include "com/themightystags/toddtris/app/AppState.h"
#include "com/themightystags/toddtris/app/PlayerSettings.h"
#include "com/themightystags/toddtris/model/Well.h"
#include "com/themightystags/toddtris/model/WellListener.h"
#include "com/themightystags/toddtris/model/TwoPlayerGame.h"
#include "com/themightystags/toddtris/control/WellController.h"
#include <vector>
#include <stdarg.h>
#include <iostream>

using com::themightystags::toddtris::model::Well;
using com::themightystags::toddtris::model::WellListener;
using com::themightystags::toddtris::model::TwoPlayerGame;
using com::themightystags::toddtris::control::WellController;
using com::themightystags::toddtris::view::RendererFactory;
using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {

				class PlayingState: public AppState { //, public WellListener {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					PlayingState(const PlayingState& object);
					PlayingState& operator=(const PlayingState& object);

				public:
					PlayingState(AppStateMachine &appStateMachine,
							const RendererFactory &rf, Well &well);

					PlayingState(AppStateMachine &appStateMachine,
							const RendererFactory &rf, Well &w0, Well &w1);

					~PlayingState();

					void process();

					void setUpToDrop(int playerIndex, bool upToDrop);

					virtual void draw(bool full) = 0;

					void leftPressed(int controllerId);
					void leftHeld(int controllerId);

					void rightPressed(int controllerId);
					void rightHeld(int controllerId);

					void upPressed(int controllerId);

					void downPressed(int controllerId);
					void downHeld(int controllerId);

					void onePressed(int controllerId);
					void twoPressed(int controllerId);
					void holdPressed(int controllerId);
					void dropPressed(int controllerId);
					virtual void pausePressed(int controllerId) = 0;

					// WellListener callback method
					// TODO Sort out whether we can render using callbacks
					// rather than endlessly in a loop in AppStateMachine
					//void wellChanged(const Well &well);

				protected:
					Well **wells;

				private:
					int numPlayers;
					WellController **controllers;
					bool *upToDrop;

					void initControllers();
				};
			}
		}
	}
}
#endif // PlayingState_H
