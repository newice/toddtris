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

////////////////////////////////////////////////////////////////////////////////
// The AppState class is the superclass for all of the games' states.
//
// Empty virtual methods exist which are invoked by the state machine framework
// in response to button presses from players.  Any state interested in a
// particular button press need simply override the relevant method to receive
// callbacks.  A virtual 'prepare' method may also be overridden by a state to
// receive a callback that this state has been entered so that it might carry
// out any required set up; for example when a paused state is entered it will
// stop the timer used by the well to automatically drop blocks.
//
// As a simple approximation to multi-threading a 'process' method may be
// overridden to perform any background processing and will be called frequently
// by the state machine framework.  Any implementation of 'process' should
// quickly return control to the framework by simply returning from this method.
// In practice this method is overridden in states where the game is in progress
// to allow blocks to fall by checking a timer and moving the blocks down when
// required.
//
// A pure virtual 'draw' method must be implemented by all states.  This method
// is responsible for rendering the current state on screen and will be invoked
// by the state machine framework.
//
// When an event occurs giving raise to a state transition the state will notify
// the state machine framework via a callback to the AppStateMachine class.
// The framework will then be responsible for handling the transition.
// For example, when the player starts a new one player game, the
// OnePlayerMenuState class will trigger a state transition by calling
// AppStateMachine::startOnePlayerGame.
////////////////////////////////////////////////////////////////////////////////
#ifndef AppState_H
#define AppState_H

#include "com/themightystags/toddtris/app/AppStateMachine.h"

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {

				class AppState {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					AppState(const AppState& object);
					AppState& operator=(const AppState& object);

				public:
					virtual ~AppState();

					virtual void leftPressed(int controllerId);
					virtual void leftHeld(int controllerId);
					virtual void leftReleased(int controllerId);

					virtual void rightPressed(int controllerId);
					virtual void rightHeld(int controllerId);
					virtual void rightReleased(int controllerId);

					virtual void upPressed(int controllerId);
					virtual void upHeld(int controllerId);
					virtual void upReleased(int controllerId);

					virtual void downPressed(int controllerId);
					virtual void downHeld(int controllerId);
					virtual void downReleased(int controllerId);

					virtual void onePressed(int controllerId);
					virtual void twoPressed(int controllerId);
					virtual void pausePressed(int controllerId);
					virtual void ghostPressed(int controllerId);
					virtual void holdPressed(int controllerId);
					virtual void dropPressed(int controllerId);

					virtual void screenshotPressed(int controllerId);

					virtual void prepare();
					virtual void process();
					//virtual void cleanup();
					void show(bool full);

				protected:
					AppState(AppStateMachine &appStateMachine,
							const RendererFactory &rf);

					AppStateMachine &appStateMachine;
					virtual void draw(bool full) = 0;

				private:
					const RendererFactory &rendererFactory;
				};
			}
		}
	}
}
#endif // AppState_H
