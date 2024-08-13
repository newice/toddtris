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

#include "com/themightystags/toddtris/view/text/TextSplashRenderer.h"
#include "com/themightystags/util/TextHelper.h"
#include <iostream>

using com::themightystags::toddtris::view::text::TextSplashRenderer;
using com::themightystags::util::TextHelper;
using namespace std;

TextSplashRenderer *TextSplashRenderer::INSTANCE = NULL;
bool TextSplashRenderer::initialised = false;
const string TextSplashRenderer::LOGO[LOGO_HEIGHT] = {
		"RRRYYYB BDDDMMMGG LLL CC",
		" R Y  B B D  M G G L C  ",
		" R YYY B  D  M G G L  C ",
		" R Y  B B D  M GG  L   C",
		" R YYYB B D  M G GLLLCC "};

TextSplashRenderer::TextSplashRenderer() {}

TextSplashRenderer::~TextSplashRenderer() {}

TextSplashRenderer &TextSplashRenderer::getInstance() {
	if (!initialised) { 
		INSTANCE = new TextSplashRenderer();
		initialised = true;
	}

	TextSplashRenderer &ret = *INSTANCE;
	return ret;
}


void TextSplashRenderer::render(bool full) {
	if (full) {
		TextHelper::clearScreen();
		int logoOffsetX = 16;
		int logoOffsetY = 6;
		int y = logoOffsetY;
		for (int i = 0; i < LOGO_HEIGHT; ++i) {
			string line = LOGO[i];

			// position the cursor to output this line
			TextHelper::gotoxy(logoOffsetX, y);

			// get the colour of the next square
			for (string::iterator iter = line.begin(); iter < line.end(); iter++) {
				int colour;
				switch (*iter) {
				case 'R':
					colour = TextHelper::BRIGHT_RED;
					break;
				case 'Y':
					colour = TextHelper::BRIGHT_YELLOW;
					break;
				case 'B':
					colour = TextHelper::BRIGHT_BLUE;
					break;
				case 'D':
					colour = TextHelper::DARK_GREY;
					break;
				case 'M':
					colour = TextHelper::BRIGHT_MAGENTA;
					break;
				case 'G':
					colour = TextHelper::BRIGHT_GREEN;
					break;
				case 'L':
					colour = TextHelper::WHITE;
					break;
				case 'C':
					colour = TextHelper::BRIGHT_CYAN;
					break;
				default:
					colour = TextHelper::BLACK;
					break;
				}
				TextHelper::setColours(colour, colour);

				// write out a square
				cout << "  ";
			}
			++y; // next line
		}
		// now write some credits
		int creditsOffsetX = logoOffsetX + 19;
		++y;
		++y;
		++y;
		++y;
		TextHelper::gotoxy(creditsOffsetX, y);
		TextHelper::useDefaultColours();
		cout << "Code: Toddy";
		++y;
		++y;
		TextHelper::gotoxy(creditsOffsetX, y);
		cout << "Music: Pete";
	}
}

