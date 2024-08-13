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
// main.cpp provides the 'main' method for the game.  It simply does some
// initialisation and then hands control to the state machine.  The
// initialisation is handled by the 'init' method in init.cpp of which different
// versions exist depending on the (a) the platform and (b) the renderer to be
// used (text-based or graphical).
////////////////////////////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/view/RendererFactory.h"
#include "com/themightystags/toddtris/app/AppStateMachine.h"
#include "com/themightystags/toddtris/sound/BGMPlayer.h"
#include "com/themightystags/toddtris/model/Randomizer.h"

#include <vector>
#include <string>
#include <iostream>

using com::themightystags::toddtris::view::RendererFactory;
using com::themightystags::toddtris::app::AppStateMachine;
using com::themightystags::toddtris::sound::BGMPlayer;

// The following functions are implemented in an init.cpp
// file for the specific platform
void init(int argc, char **argv);
const RendererFactory &getRendererFactory();

int main(int argc, char **argv) {

	// system specific init
	init(argc, argv);

	// following function defined in init.cpp
	const RendererFactory &rf = getRendererFactory();

	BGMPlayer bgmp;
	bgmp.process();

	AppStateMachine appStateMachine(rf, bgmp);
	appStateMachine.run();

	// cleanup
	BGMPlayer::end();
	rf.cleanup();

	return 0;
}

