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

#include "com/themightystags/toddtris/view/gx/GXSplashRenderer.h"

using com::themightystags::toddtris::view::gx::GXSplashRenderer;

GXSplashRenderer *GXSplashRenderer::INSTANCE = NULL;
bool GXSplashRenderer::initialised = false;
GRRLIB_texImg *GXSplashRenderer::tex_splash;

void GXSplashRenderer::init() {
	// if already initialised then we should clean up
	if (initialised) {
		cleanup();
	}
	tex_splash = loadFileTexture("splash.png");
	initialised = true;
}

void GXSplashRenderer::cleanup() {
	if (initialised) {
		GRRLIB_FreeTexture(tex_splash);
		initialised = false;
	}
}

GXSplashRenderer::GXSplashRenderer() {

	//initialise the class if required
	if (!GXSplashRenderer::initialised) {
		init();
	}
}

GXSplashRenderer::~GXSplashRenderer() {}

GXSplashRenderer &GXSplashRenderer::getInstance() {
	if (!initialised) { 
		INSTANCE = new GXSplashRenderer();
		initialised = true;
	}

	GXSplashRenderer &ret = *INSTANCE;
	return ret;
}


void GXSplashRenderer::render(bool full) {
	GRRLIB_DrawImg(0, 0, tex_splash, 0, 1, 1, 0xFFFFFFFF);
}

