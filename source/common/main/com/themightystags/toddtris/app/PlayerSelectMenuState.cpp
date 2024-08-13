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

#include "com/themightystags/toddtris/app/PlayerSelectMenuState.h"
#include <cstdlib>

using com::themightystags::toddtris::app::PlayerSelectMenuState;
using namespace std;

PlayerSelectMenuState::PlayerSelectMenuState(AppStateMachine &appStateMachine,
		const RendererFactory &rf)
		: MenuState(appStateMachine, rf), selectedOption(OnePlayer) {}

PlayerSelectMenuState::~PlayerSelectMenuState(){}

void PlayerSelectMenuState::upPressed(int controllerId){
	//behaviour same for both controllers
	switch (selectedOption) {
	case OnePlayer:
		selectedOption = Exit;
		break;
	case TwoPlayer:
		selectedOption = OnePlayer;
		break;
	case Exit:
		selectedOption = TwoPlayer;
		break;
	}
}

void PlayerSelectMenuState::downPressed(int controllerId){
	//behaviour same for both controllers
	switch (selectedOption) {
	case OnePlayer:
		selectedOption = TwoPlayer;
		break;
	case TwoPlayer:
		selectedOption = Exit;
		break;
	case Exit:
		selectedOption = OnePlayer;
		break;
	}
}

void PlayerSelectMenuState::twoPressed(int controllerId){
	switch (selectedOption) {
	case Exit:
		appStateMachine.exitApp();
		break;
	case OnePlayer:
		appStateMachine.playersSelected(1);
		break;
	case TwoPlayer:
		appStateMachine.playersSelected(2);
		break;
	}
}

void PlayerSelectMenuState::draw(bool full){
	vector<string> text;
	vector<bool> selected;

	text.push_back("one player");
	selected.push_back(selectedOption == OnePlayer);

	text.push_back("two player");
	selected.push_back(selectedOption == TwoPlayer);

	text.push_back("exit");
	selected.push_back(selectedOption == Exit);

	menuRenderer.render(text, selected, full);
}

void PlayerSelectMenuState::process() {
	// little hack to prevent the same blocks coming every time
	// advance the randomiser while the user is on the first screen
	rand();
}
