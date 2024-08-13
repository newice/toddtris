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

#include "com/themightystags/toddtris/view/gx/GXTwoPlayerRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXWellRenderer.h"

using com::themightystags::toddtris::view::gx::GXTwoPlayerRenderer;
using com::themightystags::toddtris::view::gx::GXWellRenderer;

GXTwoPlayerRenderer *GXTwoPlayerRenderer::INSTANCE = NULL;
bool GXTwoPlayerRenderer::initialised = false;

GXTwoPlayerRenderer::GXTwoPlayerRenderer()
		: wellRenderer0(WellRenderer::Left),
		wellRenderer1(WellRenderer::Right) {
}

GXTwoPlayerRenderer::~GXTwoPlayerRenderer() {}

GXTwoPlayerRenderer &GXTwoPlayerRenderer::getInstance() {
	if (!initialised) {
		INSTANCE = new GXTwoPlayerRenderer();
		initialised = true;
	}

	GXTwoPlayerRenderer &ret = *INSTANCE;
	return ret;
}

WellRenderer &GXTwoPlayerRenderer::getWellRenderer(int index) {
	if (!index) {
		return wellRenderer0;
	} else {
		return wellRenderer1;
	}
}

void GXTwoPlayerRenderer::render(const Well &w0, const Well &w1,
							const TwoPlayerGame &tpg, bool full) {
	// full ignored for GX - always full render
	showBackgroundImage();
	wellRenderer0.render(w0, full);
	wellRenderer1.render(w1, full);

	// render the score
	for (unsigned int i = 0; i < 2; ++i) {
		GXRenderer::renderInt(115 + i*320, 430, tpg.getScore(i));
	}
}

void GXTwoPlayerRenderer::render(const Well &w0, const Well &w1,
		const TwoPlayerGame &tpg,
		const vector<string> &options,
		int selectedIndex, bool full) {

	render(w0, w1, tpg, full);
	for (unsigned int i = 0; i < options.size(); ++i) {
		GXRenderer::renderMenuItem(
				240, 180 + i*30, options[i], selectedIndex == (int)i);
	}
}

