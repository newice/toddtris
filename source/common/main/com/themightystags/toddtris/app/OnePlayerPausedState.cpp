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
 * OnePlayerPausedState.cpp
 *
 *  Created on: 10-Feb-2009
 *      Author: todda
 */

#include "com/themightystags/toddtris/app/OnePlayerPausedState.h"

using com::themightystags::toddtris::app::OnePlayerPausedState;

const string OnePlayerPausedState::RESUME = "continue";
const string OnePlayerPausedState::RESTART = "restart";
const string OnePlayerPausedState::QUIT = "quit";

OnePlayerPausedState::OnePlayerPausedState(AppStateMachine &appStateMachine,
		const RendererFactory &rf, Well &well)
		: OnePlayerStoppedState(appStateMachine, rf, getOptions(), well, false) {}

OnePlayerPausedState::~OnePlayerPausedState() {}

const vector<string> OnePlayerPausedState::getOptions() {
	vector<string> options;
	options.push_back(OnePlayerPausedState::RESUME);
	options.push_back(OnePlayerPausedState::RESTART);
	options.push_back(OnePlayerPausedState::QUIT);
	return options;
}

void OnePlayerPausedState::optionSelected(string option) {
	if (option == OnePlayerPausedState::RESUME) {
		appStateMachine.resumeOnePlayer();
	} else if (option == OnePlayerPausedState::RESTART) {
		appStateMachine.restartOnePlayer();
	} else if (option == OnePlayerPausedState::QUIT) {
		appStateMachine.quit();
	}
}

