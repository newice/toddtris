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

#include "com/themightystags/toddtris/view/gx/GXOnePlayerRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXWellRenderer.h"

using com::themightystags::toddtris::view::gx::GXOnePlayerRenderer;
using com::themightystags::toddtris::view::gx::GXWellRenderer;
using com::themightystags::toddtris::view::WellRenderer;

GXOnePlayerRenderer *GXOnePlayerRenderer::INSTANCE = NULL;
bool GXOnePlayerRenderer::initialised = false;

GXOnePlayerRenderer::GXOnePlayerRenderer()
		: wellRenderer(WellRenderer::Centre) {
}

GXOnePlayerRenderer::~GXOnePlayerRenderer() {}

GXOnePlayerRenderer &GXOnePlayerRenderer::getInstance() {
	if (!initialised) {
		INSTANCE = new GXOnePlayerRenderer();
		initialised = true;
	}

	GXOnePlayerRenderer &ret = *INSTANCE;
	return ret;
}

WellRenderer &GXOnePlayerRenderer::getWellRenderer() {
	return wellRenderer;
}

void GXOnePlayerRenderer::render(const Well &well, bool full) {
	// full ignored for GX - always full render
	showBackgroundImage();
	wellRenderer.render(well, full);
}

void GXOnePlayerRenderer::render(const Well &well,
		const vector<string> &options,
		int selectedIndex, bool full) {
	render(well, full);
	for (unsigned int i = 0; i < options.size(); ++i) {
		GXRenderer::renderMenuItem(
				215, 180 + i*30, options[i], selectedIndex == (int)i);
	}
}
