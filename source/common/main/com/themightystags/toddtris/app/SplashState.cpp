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

#include "com/themightystags/toddtris/app/SplashState.h"

using com::themightystags::toddtris::app::SplashState;

SplashState::SplashState(AppStateMachine &appStateMachine,
		const RendererFactory &rf)
		: AppState(appStateMachine, rf), renderer(rf.getSplashRenderer()) {
}

SplashState::~SplashState(){
}

void SplashState::onePressed(int controllerId){
	appStateMachine.exitSplashScreen();
}

void SplashState::twoPressed(int controllerId){
	appStateMachine.exitSplashScreen();
}

void SplashState::pausePressed(int controllerId){
	appStateMachine.exitSplashScreen();
}

void SplashState::ghostPressed(int controllerId){
	appStateMachine.exitSplashScreen();
}

void SplashState::holdPressed(int controllerId){
	appStateMachine.exitSplashScreen();
}

void SplashState::dropPressed(int controllerId){
	appStateMachine.exitSplashScreen();
}

void SplashState::draw(bool full) {
	renderer.render(full);
}
