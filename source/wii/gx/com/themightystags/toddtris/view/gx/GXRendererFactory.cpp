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

#include "com/themightystags/toddtris/view/gx/GXRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXRendererFactory.h"
#include "com/themightystags/toddtris/view/gx/GXSplashRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXMenuRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXOnePlayerRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXTwoPlayerRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXWellRenderer.h"

using com::themightystags::toddtris::view::gx::GXRenderer;
using com::themightystags::toddtris::view::gx::GXRendererFactory;
using com::themightystags::toddtris::view::gx::GXSplashRenderer;
using com::themightystags::toddtris::view::gx::GXMenuRenderer;
using com::themightystags::toddtris::view::gx::GXOnePlayerRenderer;
using com::themightystags::toddtris::view::gx::GXTwoPlayerRenderer;
using com::themightystags::toddtris::view::gx::GXWellRenderer;

const GXRendererFactory GXRendererFactory::INSTANCE;

GXRendererFactory::GXRendererFactory() {}
GXRendererFactory::~GXRendererFactory() {}

SplashRenderer &GXRendererFactory::getSplashRenderer() const {
	return GXSplashRenderer::getInstance();
}

MenuRenderer &GXRendererFactory::getMenuRenderer() const {
	return GXMenuRenderer::getInstance();
}

OnePlayerRenderer &GXRendererFactory::getOnePlayerRenderer() const {
	return GXOnePlayerRenderer::getInstance();
}

TwoPlayerRenderer &GXRendererFactory::getTwoPlayerRenderer() const {
	return GXTwoPlayerRenderer::getInstance();
}

void GXRendererFactory::videoSync() const {
	GXRenderer::videoSync();
}

void GXRendererFactory::cleanup() const {
	GXWellRenderer::cleanup();
	GXSplashRenderer::cleanup();
	GXScreenRenderer::cleanup();
	GXRenderer::cleanup();
	GRRLIB_Exit();
}

void GXRendererFactory::requestScreenshot() const {
	GXRenderer::requestScreenshot();
}

const GXRendererFactory &GXRendererFactory::getInstance() {
	return INSTANCE;
}

