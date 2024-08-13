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

#include "com/themightystags/toddtris/view/text/TextMenuRenderer.h"
#include "com/themightystags/util/TextHelper.h"
#include <iostream>

using com::themightystags::toddtris::view::text::TextMenuRenderer;
using com::themightystags::util::TextHelper;
using namespace std;

TextMenuRenderer *TextMenuRenderer::INSTANCE = NULL;
bool TextMenuRenderer::initialised = false;

TextMenuRenderer::TextMenuRenderer() {}

TextMenuRenderer::~TextMenuRenderer() {}

TextMenuRenderer &TextMenuRenderer::getInstance() {
	if (!initialised) { 
		INSTANCE = new TextMenuRenderer();
		initialised = true;
	}

	TextMenuRenderer &ret = *INSTANCE;
	return ret;
}


void TextMenuRenderer::render(const vector<string> &options, 
		const vector<bool> &selected, bool full) {

	if (full || options != lastOptions || selected != lastSelected) {
		TextHelper::clearScreen();

		for (unsigned int i = 0; i < options.size(); ++i) {
		
			lastOptions = options;
			lastSelected = selected;

			int bgColour = TextHelper::BLACK;
			int fgColour = TextHelper::WHITE;
			
			if (i < selected.size() && selected[i]) {
				fgColour = TextHelper::BRIGHT_CYAN;
			}
			
			TextHelper::setColours(bgColour, fgColour);
			TextHelper::gotoxy(30, 10 + 2*i);
			cout << options[i].c_str();
		}
	}
}

