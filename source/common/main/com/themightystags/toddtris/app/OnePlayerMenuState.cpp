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

#include "com/themightystags/toddtris/app/OnePlayerMenuState.h"
#include <cstdlib>
#include <string>
#include <sstream>

using com::themightystags::toddtris::app::OnePlayerMenuState;
using namespace std;

OnePlayerMenuState::OnePlayerMenuState(AppStateMachine &appStateMachine,
		const RendererFactory &rf)
		: MenuState(appStateMachine, rf), selectedOption(Type) {}

OnePlayerMenuState::~OnePlayerMenuState(){}

void OnePlayerMenuState::leftPressed(int controllerId){
	//behaviour same for both controllers
	switch (selectedOption) {
	case Type:
		playerSettings.toggleGameType();
		break;
	case Level:
		playerSettings.decLevel();
		break;
	case Height:
		playerSettings.decHeight();
		break;
	case UpToDrop:
		playerSettings.toggleUpToDrop();
		break;
	}
}

void OnePlayerMenuState::rightPressed(int controllerId){
	//behaviour same for both controllers
	switch (selectedOption) {
	case Type:
		playerSettings.toggleGameType();
		break;
	case Level:
		playerSettings.incLevel();
		break;
	case Height:
		playerSettings.incHeight();
		break;
	case UpToDrop:
		playerSettings.toggleUpToDrop();
		break;
	}
}

void OnePlayerMenuState::upPressed(int controllerId){
	//behaviour same for both controllers
	switch (selectedOption) {
	case Type:
		selectedOption = UpToDrop;
		break;
	case Level:
		selectedOption = Type;
		break;
	case Height:
		selectedOption = Level;
		break;
	case UpToDrop:
		selectedOption = Height;
		break;
	}
}

void OnePlayerMenuState::downPressed(int controllerId){
	//behaviour same for both controllers
	switch (selectedOption) {
	case Type:
		selectedOption = Level;
		break;
	case Level:
		selectedOption = Height;
		break;
	case Height:
		selectedOption = UpToDrop;
		break;
	case UpToDrop:
		selectedOption = Type;
		break;
	}
}

void OnePlayerMenuState::onePressed(int controllerId){
	appStateMachine.cancelOnePlayerMenu();
}

void OnePlayerMenuState::twoPressed(int controllerId){
	appStateMachine.startOnePlayerGame(playerSettings);
}

void OnePlayerMenuState::draw(bool full){
	vector<string> text;
	vector<bool> selected;

	stringstream typess;
	typess << "type: ";
	typess << (playerSettings.getGameType() == Marathon ? "marathon" : "time trial");
	text.push_back(typess.str());
	selected.push_back(selectedOption == Type);

	stringstream levelss;
	levelss << "level: " << playerSettings.getLevel();
	text.push_back(levelss.str());
	selected.push_back(selectedOption == Level);

	stringstream heightss;
	heightss << "height: " << playerSettings.getHeight();
	selected.push_back(selectedOption == Height);
	text.push_back(heightss.str());

	stringstream dropss;
	dropss << "up -> hard drop: ";
	dropss << (playerSettings.isUpToDrop() ? "on" : "off");
	text.push_back(dropss.str());
	selected.push_back(selectedOption == UpToDrop);

	menuRenderer.render(text, selected, full);
}
