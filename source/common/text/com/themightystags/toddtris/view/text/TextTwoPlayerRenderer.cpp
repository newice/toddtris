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

#include "com/themightystags/toddtris/view/text/TextTwoPlayerRenderer.h"
#include "com/themightystags/toddtris/view/text/TextWellRenderer.h"
#include "com/themightystags/util/TextHelper.h"
#include <iostream>


using com::themightystags::toddtris::view::text::TextTwoPlayerRenderer;
using com::themightystags::toddtris::view::text::TextWellRenderer;
using com::themightystags::util::TextHelper;
using com::themightystags::toddtris::view::WellRenderer;

TextTwoPlayerRenderer *TextTwoPlayerRenderer::INSTANCE = NULL;
bool TextTwoPlayerRenderer::initialised = false;

TextTwoPlayerRenderer::TextTwoPlayerRenderer()
		: wellRenderer0(WellRenderer::Left), wellRenderer1(WellRenderer::Right),
		renderedOptions(NULL), renderedIndex(0) {

	renderedScores[0] = renderedScores[1] = -1;
}

TextTwoPlayerRenderer::~TextTwoPlayerRenderer() {}

TextTwoPlayerRenderer &TextTwoPlayerRenderer::getInstance() {
	if (!initialised) {
		INSTANCE = new TextTwoPlayerRenderer();
		initialised = true;
	}

	TextTwoPlayerRenderer &ret = *INSTANCE;
	return ret;
}

WellRenderer &TextTwoPlayerRenderer::getWellRenderer(int index) {
	if (!index) {
		return wellRenderer0;
	} else {
		return wellRenderer1;
	}
}

void TextTwoPlayerRenderer::render(const Well &w0, const Well &w1,
		const TwoPlayerGame &tpg, bool full) {
	if (full) {
		TextHelper::clearScreen();
	}
	wellRenderer0.render(w0, full);
	wellRenderer1.render(w1, full);

	// render the score
	for (unsigned int i = 0; i < 2; ++i) {
		int score = tpg.getScore(i);
		if (full || score != renderedScores[i]) {
			TextHelper::gotoxy(12 + i*40, 6 + Well::WELL_HEIGHT);
			TextHelper::setColours(TextHelper::BLACK, TextHelper::WHITE);
			cout << score;
			renderedScores[i] = score;
		}
	}
}

void TextTwoPlayerRenderer::render(const Well &w0, const Well &w1,
		const TwoPlayerGame &tpg,
		const vector<string> &options,
		int selectedIndex, bool full) {

	render(w0, w1, tpg, full);

	// render the options
	if (full || renderedIndex != selectedIndex || renderedOptions != &options) {
		for (unsigned int i = 0; i < options.size(); ++i) {
			TextHelper::gotoxy(8,9 + i);
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

