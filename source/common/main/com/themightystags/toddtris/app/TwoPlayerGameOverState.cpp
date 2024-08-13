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

/*
 * TwoPlayerGameOverState.cpp
 */

#include "com/themightystags/toddtris/app/TwoPlayerGameOverState.h"

using com::themightystags::toddtris::app::TwoPlayerGameOverState;

const string TwoPlayerGameOverState::AGAIN = "play again";
const string TwoPlayerGameOverState::QUIT = "quit";

TwoPlayerGameOverState::TwoPlayerGameOverState(AppStateMachine &appStateMachine,
		const RendererFactory &rf,
		Well &w0, Well &w1, TwoPlayerGame &tpg)
		: TwoPlayerStoppedState(appStateMachine, rf, getOptions(), w0, w1, tpg, true) {}

TwoPlayerGameOverState::~TwoPlayerGameOverState() {}

const vector<string> TwoPlayerGameOverState::getOptions() {
	vector<string> options;
	options.push_back(TwoPlayerGameOverState::AGAIN);
	options.push_back(TwoPlayerGameOverState::QUIT);
	return options;
}

void TwoPlayerGameOverState::optionSelected(string option) {
	if (option == TwoPlayerGameOverState::AGAIN) {
		appStateMachine.playAgainTwoPlayer();
	} else if (option == TwoPlayerGameOverState::QUIT) {
		appStateMachine.quit();
	}
}

