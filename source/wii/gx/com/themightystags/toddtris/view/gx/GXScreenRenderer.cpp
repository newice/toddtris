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

#include "com/themightystags/toddtris/view/gx/GXScreenRenderer.h"
#include <fat.h>

using com::themightystags::toddtris::view::gx::GXScreenRenderer;
using com::themightystags::toddtris::view::gx::GXRenderer;

bool GXScreenRenderer::initialised = false;
GRRLIB_texImg *GXScreenRenderer::tex_background;

void GXScreenRenderer::init() {
	// if already initialised then we should clean up
	if (initialised) {
		cleanup();
	}
	tex_background = loadFileTexture("ttbg.jpg");
	initialised = true;
}

void GXScreenRenderer::cleanup() {
	if (initialised) {
		GRRLIB_FreeTexture(tex_background);
		initialised = false;
	}
}

GXScreenRenderer::GXScreenRenderer() {

	//initialise the class if required
	if (!GXScreenRenderer::initialised) {
		init();
	}
}

GXScreenRenderer::~GXScreenRenderer() {}

/**
 * show the background image
 */
void GXScreenRenderer::showBackgroundImage() const {
	GRRLIB_DrawImg(0, 0, tex_background, 0, 1, 1, 0xFFFFFFFF);
}

