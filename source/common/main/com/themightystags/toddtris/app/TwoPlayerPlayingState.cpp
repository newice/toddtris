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

#include "com/themightystags/toddtris/app/TwoPlayerPlayingState.h"

using com::themightystags::toddtris::app::TwoPlayerPlayingState;

TwoPlayerPlayingState::TwoPlayerPlayingState(AppStateMachine &appStateMachine,
		const RendererFactory &rf, Well &w0, Well &w1, TwoPlayerGame &tpg)
		: PlayingState(appStateMachine, rf, w0, w1), tpg(tpg),
		renderer(rf.getTwoPlayerRenderer()) {
}

TwoPlayerPlayingState::~TwoPlayerPlayingState(){
}

void TwoPlayerPlayingState::pausePressed(int controllerId){
	appStateMachine.pauseTwoPlayer();
}

void TwoPlayerPlayingState::ghostPressed(int controllerId){
	renderer.toggleGhost(controllerId);
}

void TwoPlayerPlayingState::draw(bool full) {
	Well &w1 = *(wells[0]);
	Well &w2 = *(wells[1]);
	renderer.render(w1, w2, tpg, full);
}

