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

#include "com/themightystags/toddtris/view/text/TextOnePlayerRenderer.h"
#include "com/themightystags/toddtris/view/text/TextWellRenderer.h"
#include "com/themightystags/util/TextHelper.h"
#include <iostream>

using com::themightystags::toddtris::view::text::TextOnePlayerRenderer;
using com::themightystags::toddtris::view::text::TextWellRenderer;
using com::themightystags::toddtris::view::WellRenderer;
using com::themightystags::util::TextHelper;

TextOnePlayerRenderer *TextOnePlayerRenderer::INSTANCE = NULL;
bool TextOnePlayerRenderer::initialised = false;

TextOnePlayerRenderer::TextOnePlayerRenderer()
		: wellRenderer(WellRenderer::Centre), renderedOptions(NULL), renderedIndex(0) {
}

TextOnePlayerRenderer::~TextOnePlayerRenderer() {}

TextOnePlayerRenderer &TextOnePlayerRenderer::getInstance() {
	if (!initialised) {
		INSTANCE = new TextOnePlayerRenderer();
		initialised = true;
	}

	TextOnePlayerRenderer &ret = *INSTANCE;
	return ret;
}

WellRenderer &TextOnePlayerRenderer::getWellRenderer() {
	return wellRenderer;
}

void TextOnePlayerRenderer::render(const Well &well, bool full) {
	if (full) {
		TextHelper::clearScreen();
	}
	wellRenderer.render(well, full);
}

void TextOnePlayerRenderer::render(const Well &well,
		const vector<string> &options,
		int selectedIndex, bool full) {

	render(well, full);

	// render the options
	if (full || renderedIndex != selectedIndex || renderedOptions != &options) {
		for (unsigned int i = 0; i < options.size(); ++i) {
			TextHelper::gotoxy(28,9 + i);
			int bgColour = TextHelper::BLACK;
			int fgColour = (selectedIndex == (int)i)
					? TextHelper::CYAN : TextHelper::WHITE;
			TextHelper::setColours(bgColour, fgColour);
			cout << options[i];
		}
		renderedIndex = selectedIndex;
		renderedOptions = &options;
	}
}

