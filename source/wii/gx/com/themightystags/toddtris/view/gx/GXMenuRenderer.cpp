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

#include "com/themightystags/toddtris/view/gx/GXMenuRenderer.h"

using com::themightystags::toddtris::view::gx::GXMenuRenderer;

GXMenuRenderer *GXMenuRenderer::INSTANCE = NULL;
bool GXMenuRenderer::initialised = false;


GXMenuRenderer::GXMenuRenderer() {}

GXMenuRenderer::~GXMenuRenderer() {}

void GXMenuRenderer::render(const vector<string> &options,
		const vector<bool> &selected, bool full) {

	// ignore full parameter, always render full screen
	showBackgroundImage();

	// calculate the how high on the screen to draw the menu
	int yStart = (selected.size() < 7) ? 150 : 100 - ((selected.size() - 6) * 50);
	if (yStart < 0) {
		yStart = 0;
	}

	// draw each menu item
	for (unsigned int i = 0; i < options.size(); ++i) {
		bool highlight = (i < selected.size() && selected[i]);
		GXRenderer::renderMenuItem(220, yStart + i*50, options[i], highlight);
	}
}

GXMenuRenderer &GXMenuRenderer::getInstance() {

	if (!initialised) {
		INSTANCE = new GXMenuRenderer();
		initialised = true;
	}

	GXMenuRenderer &ret = *INSTANCE;
	return ret;
}
