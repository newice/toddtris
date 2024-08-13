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
// A state machine pattern is used to handle the different logical states the
// game may be – in menu system, playing one player game, playing two player game,
// paused, game over, etc.  Depending on the current state input will be handled
// differently and may cause transition to another state.
//
// AppStateMachine is responsible for reading the input state (i.e. button
// presses) and calling the relevant methods on the current state in response to
// those button presses.  AppStateMachine will also call the 'process' method on
// each state after reading the input as described in the previous section and
// then request that the state render itself.  This process is repeated in an loop
// until the 'exitApp' method is called.  A number of methods are provided which
// the current state may use to invoke state transitions.
////////////////////////////////////////////////////////////////////////////////

#ifndef AppStateMachine_H
#define AppStateMachine_H

#include "com/themightystags/toddtris/app/PlayerSettings.h"
#include "com/themightystags/toddtris/view/RendererFactory.h"
#include "com/themightystags/toddtris/sound/BGMPlayer.h"
#include "com/themightystags/toddtris/model/Well.h"
#include "com/themightystags/toddtris/model/WellListener.h"
#include "com/themightystags/toddtris/model/TwoPlayerGame.h"

using com::themightystags::toddtris::view::RendererFactory;
using com::themightystags::toddtris::sound::BGMPlayer;
using com::themightystags::toddtris::model::Well;
using com::themightystags::toddtris::model::WellListener;
using com::themightystags::toddtris::model::TwoPlayerGame;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {

				class AppState;
				class SplashState;
				class PlayerSelectMenuState;
				class OnePlayerMenuState;
				class TwoPlayerMenuState;
				class OnePlayerPlayingState;
				class OnePlayerPausedState;
				class OnePlayerGameOverState;
				class TwoPlayerPlayingState;
				class TwoPlayerPausedState;
				class TwoPlayerGameOverState;

				class AppStateMachine : public WellListener {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					AppStateMachine(const AppStateMachine& object);
					AppStateMachine& operator=(const AppStateMachine& object);

					void applyWellSettings(Well &well, const PlayerSettings &playerSettings);

				public:
					static const int TIME_TRIAL_LINES = 40;

					AppStateMachine(const RendererFactory &rf, BGMPlayer &bgmp);
					~AppStateMachine();

					void exitSplashScreen();

					void playersSelected(int numPlayers);
					void exitApp();

					void cancelOnePlayerMenu();
					void cancelTwoPlayerMenu();

					void startOnePlayerGame(const PlayerSettings &playerSettings);
					void startTwoPlayerGame(const PlayerSettings (&playerSettings)[2]);

					void pauseOnePlayer();
					void resumeOnePlayer();
					void restartOnePlayer();

					void pauseTwoPlayer();
					void resumeTwoPlayer();
					void playAgainTwoPlayer();

					void quit();

					void gameOver(const Well &well);

					void run();

				private:
					Well well0;
					Well well1;
					TwoPlayerGame tpg;
					SplashState *splashState;
					PlayerSelectMenuState *playerSelectMenuState;
					OnePlayerMenuState *onePlayerMenuState;
					TwoPlayerMenuState *twoPlayerMenuState;
					OnePlayerPlayingState *onePlayerPlayingState;
					OnePlayerPausedState *onePlayerPausedState;
					OnePlayerGameOverState *onePlayerGameOverState;
					TwoPlayerPlayingState *twoPlayerPlayingState;
					TwoPlayerPausedState *twoPlayerPausedState;
					TwoPlayerGameOverState *twoPlayerGameOverState;
					AppState *currentState;
					BGMPlayer &bgmPlayer;
					bool exitRequested;

					void setState(AppState *state);
				};
			}
		}
	}
}
#endif // AppStateMachine_H
