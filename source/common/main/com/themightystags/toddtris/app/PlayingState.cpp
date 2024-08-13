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

#include "com/themightystags/toddtris/app/PlayingState.h"

using com::themightystags::toddtris::app::PlayingState;
using com::themightystags::toddtris::control::WellController;
using com::themightystags::toddtris::model::Well;

void PlayingState::initControllers(){
	controllers = new WellController *[numPlayers];
	for (int i = 0; i < numPlayers; ++i) {
		Well &well = *(wells[i]);
		controllers[i] = new WellController(well);
	}
}
PlayingState::PlayingState(AppStateMachine &appStateMachine,
		const RendererFactory &rf, Well &well)
		: AppState(appStateMachine, rf), numPlayers(1) {

	wells = new Well *[numPlayers];
	wells[0] = &well;
	upToDrop = new bool[numPlayers];
	upToDrop[0] = false;
	initControllers();
}

PlayingState::PlayingState(AppStateMachine &appStateMachine,
		const RendererFactory &rf, Well &w0, Well &w1)
		: AppState(appStateMachine, rf), numPlayers(2) {

	wells = new Well *[numPlayers];
	wells[0] = &w0;
	wells[1] = &w1;
	upToDrop = new bool[numPlayers];
	upToDrop[0] = false;
	upToDrop[1] = false;
	initControllers();
}

PlayingState::~PlayingState(){
	for (int i = 0; i < numPlayers; ++i) {
		delete controllers[i];
	}
	delete[] controllers;
	delete[] wells;
	delete[] upToDrop;
}

void PlayingState::process(){
	for (int i = 0; i < numPlayers; ++i) {
		wells[i]->process();
	}
}

void PlayingState::setUpToDrop(int playerIndex, bool upToDrop){
	PlayingState::upToDrop[playerIndex] = upToDrop;
}

void PlayingState::leftPressed(int controllerId){
	if (controllerId >= numPlayers) {
		controllerId = 0;
	}
	controllers[controllerId]->leftPressed();
}

void PlayingState::leftHeld(int controllerId){
	if (controllerId >= numPlayers) {
		controllerId = 0;
	}
	controllers[controllerId]->leftHeld();
}

void PlayingState::rightPressed(int controllerId){
	if (controllerId >= numPlayers) {
		controllerId = 0;
	}
	controllers[controllerId]->rightPressed();
}
void PlayingState::rightHeld(int controllerId){
	if (controllerId >= numPlayers) {
		controllerId = 0;
	}
	controllers[controllerId]->rightHeld();
}

void PlayingState::upPressed(int controllerId){
	if (controllerId >= numPlayers) {
		controllerId = 0;
	}
	if (upToDrop[controllerId]) {
		controllers[controllerId]->drop();
	}
}

void PlayingState::downPressed(int controllerId){
	if (controllerId >= numPlayers) {
		controllerId = 0;
	}
	controllers[controllerId]->downPressed();
}
void PlayingState::downHeld(int controllerId){
	if (controllerId >= numPlayers) {
		controllerId = 0;
	}
	controllers[controllerId]->downHeld();
}

void PlayingState::onePressed(int controllerId){
	if (controllerId >= numPlayers) {
		controllerId = 0;
	}
	controllers[controllerId]->antirotate();
}

void PlayingState::twoPressed(int controllerId){
	if (controllerId >= numPlayers) {
		controllerId = 0;
	}
	controllers[controllerId]->rotate();
}

void PlayingState::holdPressed(int controllerId){
//	Commented this out as I don't approve of the 'hold' facility
//	if (controllerId >= numPlayers) {
//		controllerId = 0;
//	}
//	controllers[controllerId]->hold();
}

void PlayingState::dropPressed(int controllerId){
	if (controllerId >= numPlayers) {
		controllerId = 0;
	}
	controllers[controllerId]->drop();
}

//void PlayingState::wellChanged(const Well &well) {
//	show(false);
//}
