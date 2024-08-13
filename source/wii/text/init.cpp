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
// See main.cpp for description
//
////////////////////////////////////////////////////////////////////////////////

#include <fat.h>

#include "com/themightystags/toddtris/view/text/TextRendererFactory.h"
#include "com/themightystags/util/TextHelper.h"
#include "com/themightystags/util/PathUtil.h"
#include "com/themightystags/toddtris/sound/BGMPlayer.h"

using com::themightystags::toddtris::view::text::TextRendererFactory;
using com::themightystags::util::TextHelper;
using com::themightystags::util::PathUtil;
using com::themightystags::toddtris::sound::BGMPlayer;

void init(int argc, char **argv) {

	/*
	 * Init the file system so we can load sounds
	 */
	fatInitDefault ();

	/*
	 * Find the path to our sounds, this is done by taking the
	 * path to the application and looking in the "sounds" directory.
	 *
	 * Take the separator character to be last character in the path
	 * if this exists
	 */
	const string path = (argc > 0) ? argv[0] : "sd:/"; //argc should never by 0
	const string workingDir = PathUtil::getDir(path);
	const char sep = PathUtil::getSeparator(path);

	/*
	 * Initialise the BGM player
	 */
	const string soundDir = workingDir + "sounds" + sep;
	BGMPlayer::init(soundDir);

	/*
	 * Initialise text
	 */
	TextHelper::init();
}

const RendererFactory &getRendererFactory() {
	return TextRendererFactory::getInstance();
}
