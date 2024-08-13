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
//
// See AppStateMachine.h for detailed description
//
////////////////////////////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/app/AppStateMachine.h"

#include "com/themightystags/toddtris/app/SplashState.h"
#include "com/themightystags/toddtris/app/PlayerSelectMenuState.h"
#include "com/themightystags/toddtris/app/OnePlayerMenuState.h"
#include "com/themightystags/toddtris/app/TwoPlayerMenuState.h"
#include "com/themightystags/toddtris/app/OnePlayerPlayingState.h"
#include "com/themightystags/toddtris/app/OnePlayerPausedState.h"
#include "com/themightystags/toddtris/app/OnePlayerGameOverState.h"
#include "com/themightystags/toddtris/app/TwoPlayerPlayingState.h"
#include "com/themightystags/toddtris/app/TwoPlayerPausedState.h"
#include "com/themightystags/toddtris/app/TwoPlayerGameOverState.h"
#include "com/themightystags/toddtris/input/InputReader.h"

using com::themightystags::toddtris::app::AppStateMachine;
using com::themightystags::toddtris::app::SplashState;
using com::themightystags::toddtris::app::PlayerSelectMenuState;
using com::themightystags::toddtris::app::OnePlayerMenuState;
using com::themightystags::toddtris::app::TwoPlayerMenuState;
using com::themightystags::toddtris::app::OnePlayerPlayingState;
using com::themightystags::toddtris::app::OnePlayerPausedState;
using com::themightystags::toddtris::app::OnePlayerGameOverState;
using com::themightystags::toddtris::app::TwoPlayerPlayingState;
using com::themightystags::toddtris::app::TwoPlayerPausedState;
using com::themightystags::toddtris::app::TwoPlayerGameOverState;
using com::themightystags::toddtris::input::InputReader;
using com::themightystags::toddtris::input::InputState;

AppStateMachine::AppStateMachine(const RendererFactory &rf,
		BGMPlayer &bgmp) : well0(0, 0, 0), well1(0, 0, 0),
		tpg(well0, well1), bgmPlayer(bgmp), exitRequested(false) {

	well0.addListener(*this);
	well1.addListener(*this);
	splashState = new SplashState(*this, rf);
	playerSelectMenuState = new PlayerSelectMenuState(*this, rf);
	onePlayerMenuState = new OnePlayerMenuState(*this, rf);
	twoPlayerMenuState = new TwoPlayerMenuState(*this, rf);
	onePlayerPlayingState = new OnePlayerPlayingState(*this, rf, well0);
	onePlayerPausedState = new OnePlayerPausedState(*this, rf, well0);
	onePlayerGameOverState = new OnePlayerGameOverState(*this, rf, well0);
	twoPlayerPlayingState = new TwoPlayerPlayingState(*this, rf, well0, well1, tpg);
	twoPlayerPausedState = new TwoPlayerPausedState(*this, rf, well0, well1, tpg);
	twoPlayerGameOverState = new TwoPlayerGameOverState(*this, rf, well0, well1, tpg);
	setState(splashState);
}

AppStateMachine::~AppStateMachine() {
	delete splashState;
	delete playerSelectMenuState;
	delete onePlayerMenuState;
	delete twoPlayerMenuState;
	delete onePlayerPlayingState;
	delete onePlayerPausedState;
	delete onePlayerGameOverState;
	delete twoPlayerPlayingState;
	delete twoPlayerPausedState;
	delete twoPlayerGameOverState;
}

void AppStateMachine::exitSplashScreen() {
	setState(playerSelectMenuState);
}


void AppStateMachine::playersSelected(int numPlayers) {
	if (numPlayers == 1) {
		setState(onePlayerMenuState);
	} else {
		setState(twoPlayerMenuState);
	}
}

void AppStateMachine::exitApp() {
	exitRequested = true;
}

void AppStateMachine::cancelOnePlayerMenu() {
	setState(playerSelectMenuState);
}

void AppStateMachine::cancelTwoPlayerMenu() {
	setState(playerSelectMenuState);
}

void AppStateMachine::applyWellSettings(Well &well, const PlayerSettings &playerSettings) {
	int targetLines = playerSettings.getGameType() == Marathon
			? 0 : TIME_TRIAL_LINES;
	well.updateChallengeSettings(targetLines,
			playerSettings.getHeight(), playerSettings.getLevel());
	well.reset();
}

void AppStateMachine::startOnePlayerGame(const PlayerSettings &playerSettings) {
	applyWellSettings(well0, playerSettings);
	well0.startWell();
	onePlayerPlayingState->setUpToDrop(0, playerSettings.isUpToDrop());
	setState(onePlayerPlayingState);
}

void AppStateMachine::startTwoPlayerGame(const PlayerSettings (&playerSettings)[2]) {
	applyWellSettings(well0, playerSettings[0]);
	applyWellSettings(well1, playerSettings[1]);
	twoPlayerPlayingState->setUpToDrop(0, playerSettings[0].isUpToDrop());
	twoPlayerPlayingState->setUpToDrop(1, playerSettings[1].isUpToDrop());
	tpg.newGame();
	setState(twoPlayerPlayingState);
}

void AppStateMachine::quit() {
	setState(playerSelectMenuState);
}

void AppStateMachine::pauseOnePlayer(){
	well0.stopWell();
	setState(onePlayerPausedState);
}

void AppStateMachine::resumeOnePlayer(){
	well0.startWell();
	setState(onePlayerPlayingState);
}

void AppStateMachine::restartOnePlayer(){
	well0.reset();
	well0.startWell();
	setState(onePlayerPlayingState);
}

void AppStateMachine::pauseTwoPlayer(){
	tpg.pause();
	setState(twoPlayerPausedState);
}

void AppStateMachine::resumeTwoPlayer(){
	tpg.resume();
	setState(twoPlayerPlayingState);
}

void AppStateMachine::playAgainTwoPlayer(){
	tpg.playAgain();
	setState(twoPlayerPlayingState);
}

/**
 * This WellListener method will be invoked when via a call back from the
 * well when it is game over
 */
void AppStateMachine::gameOver(const Well &well){
	if (currentState == onePlayerPlayingState) {
		setState(onePlayerGameOverState);
	} else if (currentState == twoPlayerPlayingState) {
		setState(twoPlayerGameOverState);
	}
}


void AppStateMachine::setState(AppState *state) {
	state->prepare();
	currentState = state;
	currentState->show(true);
}

void AppStateMachine::run() {
	/*
	 * Main loop with accepts input and invokes the controllers
	 */
	while(!exitRequested) {

		InputState inputState = InputReader::getInputState();

		for (int i = 0; i < 2; ++i) {

			// Check for up movement.
			if ( inputState.upPressed[i] ) currentState->upPressed(i);
			if ( inputState.upHeld[i] ) currentState->upHeld(i);
			if ( inputState.upReleased[i] ) currentState->upReleased(i);

			// Check for down movement.
			if ( inputState.downPressed[i] ) currentState->downPressed(i);
			if ( inputState.downHeld[i] ) currentState->downHeld(i);
			if ( inputState.downReleased[i] ) currentState->downReleased(i);

			// Check for left movement.
			if ( inputState.leftPressed[i] ) currentState->leftPressed(i);
			if ( inputState.leftHeld[i] ) currentState->leftHeld(i);
			if ( inputState.leftReleased[i] ) currentState->leftReleased(i);

			// Check for right movement.
			if ( inputState.rightPressed[i] ) currentState->rightPressed(i);
			if ( inputState.rightHeld[i] ) currentState->rightHeld(i);
			if ( inputState.rightReleased[i] ) currentState->rightReleased(i);

			// Look for other key presses.
			if ( inputState.antirotatePressed[i] ) currentState->onePressed(i);
			if ( inputState.rotatePressed[i] ) currentState->twoPressed(i);
			if ( inputState.pausePressed[i] ) currentState->pausePressed(i);
			if ( inputState.ghostPressed[i] ) currentState->ghostPressed(i);
			if ( inputState.holdPressed[i] ) currentState->holdPressed(i);
			if ( inputState.dropPressed[i] ) currentState->dropPressed(i);
			if ( inputState.screenshotPressed[i] ) currentState->screenshotPressed(i);

            currentState->process();
			bgmPlayer.process();
		}

		currentState->show(false);
	}
}

