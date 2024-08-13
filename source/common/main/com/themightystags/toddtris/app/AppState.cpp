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
// See AppState.h for detailed description
//
////////////////////////////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/app/AppState.h"

using com::themightystags::toddtris::app::AppState;

AppState::AppState(AppStateMachine &appStateMachine, const RendererFactory &rf)
		: appStateMachine(appStateMachine), rendererFactory(rf) {}

AppState::~AppState(){}

void AppState::leftPressed(int controllerId){}
void AppState::leftHeld(int controllerId){}
void AppState::leftReleased(int controllerId){}

void AppState::rightPressed(int controllerId){}
void AppState::rightHeld(int controllerId){}
void AppState::rightReleased(int controllerId){}

void AppState::upPressed(int controllerId){}
void AppState::upHeld(int controllerId){}
void AppState::upReleased(int controllerId){}

void AppState::downPressed(int controllerId){}
void AppState::downHeld(int controllerId){}
void AppState::downReleased(int controllerId){}

void AppState::onePressed(int controllerId){}
void AppState::twoPressed(int controllerId){}
void AppState::pausePressed(int controllerId){}
void AppState::ghostPressed(int controllerId){}
void AppState::holdPressed(int controllerId){}
void AppState::dropPressed(int controllerId){}

// by default this can be done in any app state
void AppState::screenshotPressed(int controllerId){
	rendererFactory.requestScreenshot();
}

void AppState::prepare(){}
void AppState::process(){}
//void AppState::cleanup(){}

void AppState::show(bool full){
	this->draw(full);
	rendererFactory.videoSync();
}
