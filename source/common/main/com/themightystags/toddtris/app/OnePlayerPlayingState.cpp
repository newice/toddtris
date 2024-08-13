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

#include "com/themightystags/toddtris/app/OnePlayerPlayingState.h"

using com::themightystags::toddtris::app::OnePlayerPlayingState;

OnePlayerPlayingState::OnePlayerPlayingState(AppStateMachine &appStateMachine,
		const RendererFactory &rf, Well &well) : PlayingState(appStateMachine, rf, well),
		renderer(rf.getOnePlayerRenderer()) {
}

OnePlayerPlayingState::~OnePlayerPlayingState() {}

void OnePlayerPlayingState::pausePressed(int controllerId){
	appStateMachine.pauseOnePlayer();
}

void OnePlayerPlayingState::ghostPressed(int controllerId){
	renderer.toggleGhost();
}

void OnePlayerPlayingState::draw(bool full) {
	Well &well = *(wells[0]);
	renderer.render(well, full);
}
