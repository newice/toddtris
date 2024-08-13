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
 * OnePlayerGameOverState.cpp
 */

#include "com/themightystags/toddtris/app/OnePlayerGameOverState.h"

using com::themightystags::toddtris::app::OnePlayerGameOverState;

const string OnePlayerGameOverState::RESTART = "restart";
const string OnePlayerGameOverState::QUIT = "quit";

OnePlayerGameOverState::OnePlayerGameOverState(AppStateMachine &appStateMachine,
		const RendererFactory &rf, Well &well)
		: OnePlayerStoppedState(appStateMachine, rf, getOptions(), well, true) {}

OnePlayerGameOverState::~OnePlayerGameOverState() {}

const vector<string> OnePlayerGameOverState::getOptions() {
	vector<string> options;
	options.push_back(OnePlayerGameOverState::RESTART);
	options.push_back(OnePlayerGameOverState::QUIT);
	return options;
}

void OnePlayerGameOverState::optionSelected(string option) {
	if (option == OnePlayerGameOverState::RESTART) {
		appStateMachine.restartOnePlayer();
	} else if (option == OnePlayerGameOverState::QUIT) {
		appStateMachine.quit();
	}
}

