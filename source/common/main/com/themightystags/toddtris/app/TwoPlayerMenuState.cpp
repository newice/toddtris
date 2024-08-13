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

#include "com/themightystags/toddtris/app/TwoPlayerMenuState.h"
#include <cstdlib>
#include <string>
#include <sstream>

using com::themightystags::toddtris::app::TwoPlayerMenuState;

TwoPlayerMenuState::TwoPlayerMenuState(AppStateMachine &appStateMachine, const RendererFactory &rf)
		: MenuState(appStateMachine, rf) {
	selectedOption[0] = Level;
	selectedOption[1] = Level;
}

TwoPlayerMenuState::~TwoPlayerMenuState(){}

void TwoPlayerMenuState::leftPressed(int controllerId){
	switch (selectedOption[controllerId]) {
	case Level:
		playerSettings[controllerId].decLevel();
		break;
	case Height:
		playerSettings[controllerId].decHeight();
		break;
	case UpToDrop:
		playerSettings[controllerId].toggleUpToDrop();
		break;
	}
}

void TwoPlayerMenuState::rightPressed(int controllerId){
	switch (selectedOption[controllerId]) {
	case Level:
		playerSettings[controllerId].incLevel();
		break;
	case Height:
		playerSettings[controllerId].incHeight();
		break;
	case UpToDrop:
		playerSettings[controllerId].toggleUpToDrop();
		break;
	}
}

void TwoPlayerMenuState::upPressed(int controllerId){
	switch (selectedOption[controllerId]) {
	case Level:
		selectedOption[controllerId] = UpToDrop;
		break;
	case Height:
		selectedOption[controllerId] = Level;
		break;
	case UpToDrop:
		selectedOption[controllerId] = Height;
		break;
	}
}

void TwoPlayerMenuState::downPressed(int controllerId){
	switch (selectedOption[controllerId]) {
	case Level:
		selectedOption[controllerId] = Height;
		break;
	case Height:
		selectedOption[controllerId] = UpToDrop;
		break;
	case UpToDrop:
		selectedOption[controllerId] = Level;
		break;
	}
}

void TwoPlayerMenuState::onePressed(int controllerId){
	appStateMachine.cancelTwoPlayerMenu();
}

void TwoPlayerMenuState::twoPressed(int controllerId){
	appStateMachine.startTwoPlayerGame(playerSettings);
}

void TwoPlayerMenuState::draw(bool full){
	vector<string> text;
	vector<bool> selected;

	for (int i = 0; i < 2; ++i) {
		stringstream levelss;
		levelss << "level: " << playerSettings[i].getLevel();
		text.push_back(levelss.str());
		selected.push_back(selectedOption[i] == Level);

		stringstream heightss;
		heightss << "height: " << playerSettings[i].getHeight();
		text.push_back(heightss.str());
		selected.push_back(selectedOption[i] == Height);

		stringstream dropss;
		dropss << "up -> drop: ";
		dropss << (playerSettings[i].isUpToDrop() ? "on" : "off");
		text.push_back(dropss.str());
		selected.push_back(selectedOption[i] == UpToDrop);

		// blank line between two players
		if (i == 0) {
			text.push_back("");
			selected.push_back(false);
		}
	}
	menuRenderer.render(text, selected, full);
}
