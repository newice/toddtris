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

#include "com/themightystags/toddtris/app/GameStoppedState.h"
#include <cstdlib>
#include <iostream>

using com::themightystags::toddtris::app::GameStoppedState;
using namespace std;

//GameStoppedState::GameStoppedState(AppStateMachine &appStateMachine,
//		const RendererFactory &rf,
//		const vector<string> options)
//		: AppState(appStateMachine, rf), options(options), selectedIndex(0) {
//}

GameStoppedState::GameStoppedState(AppStateMachine &appStateMachine,
		const RendererFactory &rf,
		const vector<string> options,
		bool freezeOnEntry)
		: AppState(appStateMachine, rf),
		options(options),
		selectedIndex(0),
		freezeTime(freezeOnEntry ? DEFAULT_FREEZE_TIME : 0) {
}

GameStoppedState::~GameStoppedState(){}

void GameStoppedState::prepare() {
	// freeze input and highlight the first option
	freezeTimer.setTimeout(freezeTime);
	selectedIndex = 0;
}

void GameStoppedState::draw(bool full) {
	//if the time out is not reached, don't highlight a selected option
	//delegate to the subclass to do the drawing
	int highlightIndex = freezeTimer.isTimeoutReached() ? (int)selectedIndex : -1;
	draw(full, options, highlightIndex);
}

void GameStoppedState::upPressed(int controllerId){
	//behaviour same for both controllers
	if (freezeTimer.isTimeoutReached()) {
		selectedIndex = (selectedIndex - 1)%options.size();
	}
}

void GameStoppedState::downPressed(int controllerId){
	//behaviour same for both controllers
	if (freezeTimer.isTimeoutReached()) {
		selectedIndex = (selectedIndex + 1)%options.size();
	}
}

void GameStoppedState::optionSelected() {
	// subclass should implement the following method and respond accordingly
	this->optionSelected(options[selectedIndex]);
}

void GameStoppedState::twoPressed(int controllerId){
	if (freezeTimer.isTimeoutReached()) {
		optionSelected();
	}
}

void GameStoppedState::onePressed(int controllerId){
	if (freezeTimer.isTimeoutReached()) {
		optionSelected();
	}
}

void GameStoppedState::pausePressed(int controllerId){
	if (freezeTimer.isTimeoutReached()) {
		optionSelected();
	}
}

