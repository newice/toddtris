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
 * TwoPlayerStoppedState.cpp
 */

#include "com/themightystags/toddtris/app/TwoPlayerStoppedState.h"

using com::themightystags::toddtris::app::TwoPlayerStoppedState;


TwoPlayerStoppedState::TwoPlayerStoppedState(AppStateMachine &appStateMachine,
		const RendererFactory &rf,
		const vector<string> options,
		Well &w0, Well &w1, TwoPlayerGame &tpg,
		bool freezeOnEntry)
		: GameStoppedState(appStateMachine, rf, options, freezeOnEntry),
		renderer(rf.getTwoPlayerRenderer()), well0(w0), well1(w1), tpg(tpg) {}

TwoPlayerStoppedState::~TwoPlayerStoppedState() {}

void TwoPlayerStoppedState::draw(bool full,
		const vector<string> &options, int selectedIndex) {
	renderer.render(well0, well1, tpg, options, selectedIndex, full);
}
