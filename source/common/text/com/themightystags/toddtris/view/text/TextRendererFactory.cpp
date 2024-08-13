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

#include "com/themightystags/toddtris/view/text/TextRendererFactory.h"
#include "com/themightystags/toddtris/view/text/TextSplashRenderer.h"
#include "com/themightystags/toddtris/view/text/TextMenuRenderer.h"
#include "com/themightystags/toddtris/view/text/TextOnePlayerRenderer.h"
#include "com/themightystags/toddtris/view/text/TextTwoPlayerRenderer.h"
#include "com/themightystags/toddtris/view/text/TextWellRenderer.h"

using com::themightystags::toddtris::view::text::TextRendererFactory;
using com::themightystags::toddtris::view::text::TextSplashRenderer;
using com::themightystags::toddtris::view::text::TextMenuRenderer;
using com::themightystags::toddtris::view::text::TextOnePlayerRenderer;
using com::themightystags::toddtris::view::text::TextTwoPlayerRenderer;
using com::themightystags::toddtris::view::text::TextWellRenderer;

const TextRendererFactory TextRendererFactory::INSTANCE;

TextRendererFactory::TextRendererFactory() {}
TextRendererFactory::~TextRendererFactory() {}

SplashRenderer &TextRendererFactory::getSplashRenderer() const {
	return TextSplashRenderer::getInstance();
}

MenuRenderer &TextRendererFactory::getMenuRenderer() const {
	return TextMenuRenderer::getInstance();
}

OnePlayerRenderer &TextRendererFactory::getOnePlayerRenderer() const {
	return TextOnePlayerRenderer::getInstance();
}

TwoPlayerRenderer &TextRendererFactory::getTwoPlayerRenderer() const {
	return TextTwoPlayerRenderer::getInstance();
}

void TextRendererFactory::videoSync() const {
	// nothing
}

const TextRendererFactory &TextRendererFactory::getInstance() {
	return INSTANCE;
}

void TextRendererFactory::cleanup() const {
}


