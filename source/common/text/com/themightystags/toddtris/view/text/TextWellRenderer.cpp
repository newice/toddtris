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

#include "com/themightystags/toddtris/view/text/TextWellRenderer.h"
#include "com/themightystags/util/TextHelper.h"
#include <iostream>

using com::themightystags::toddtris::view::text::TextWellRenderer;
using com::themightystags::util::TextHelper;
using namespace std;

TextWellRenderer::TextWellRenderer(WellPosition pos) : WellRenderer(true) {
	xOffset = 1;
	switch (pos) {
	case WellRenderer::Left:
		xOffset = 1;
		break;
	case WellRenderer::Centre:
		xOffset = 21;
		break;
	case WellRenderer::Right:
		xOffset = 41;
		break;
	}
	yOffset = 4;
	xOffsetNB = xOffset + ELEMENT_WIDTH * Well::WELL_WIDTH + 6;
	yOffsetNB = yOffset + 3;
	xOffsetScore = xOffsetNB - 2;
	yOffsetScore = yOffsetNB + 5;
	xOffsetTime = xOffsetScore;
	yOffsetTime = yOffsetScore + 3;
	xOffsetHB = xOffset + ELEMENT_WIDTH * Well::WELL_WIDTH + 6;
	yOffsetHB = yOffsetTime + 3;
}

TextWellRenderer::~TextWellRenderer() {}

/**
 * draw an element in the required place
 */
void TextWellRenderer::drawElem(int blockNum, int col, int row) {
	TextHelper::gotoxy(ELEMENT_WIDTH * col + xOffset + 1, row + yOffset);
	renderElem(blockNum);
}

/**
 * display the next block
 */
void TextWellRenderer::showNext(const Block &block) {
	for (int x = 0; x < Block::MAX_BLOCK_SIZE; ++x) {
		for (int y = 0; y < Block::MAX_BLOCK_SIZE; ++y) {
			TextHelper::gotoxy(ELEMENT_WIDTH * x + xOffsetNB, y + yOffsetNB);
			renderElem(block.getElem(x, y));
		}
	}
}

/**
 * display the hold block
 */
void TextWellRenderer::showHold(const Block *block) {
	for (int x = 0; x < Block::MAX_BLOCK_SIZE; ++x) {
		for (int y = 0; y < Block::MAX_BLOCK_SIZE; ++y) {
			TextHelper::gotoxy(ELEMENT_WIDTH * x + xOffsetHB, y + yOffsetHB);
			int elem = (NULL == block) ? 0 : block->getElem(x,y);
			renderElem(elem);
		}
	}
}

/**
 * show the background image
 */
void TextWellRenderer::showWellSurround() {

	TextHelper::useDefaultColours();
	// put the border around the well
	for (int y = 0; y < Well::WELL_HEIGHT; ++y) {
		TextHelper::gotoxy(xOffset, yOffset + y);
		cout << "|";
		TextHelper::gotoxy(xOffset + ELEMENT_WIDTH * Well::WELL_WIDTH + 1,
				yOffset + y);
		cout << "|";
	}
	for (int x = 0; x <= ELEMENT_WIDTH * Well::WELL_WIDTH + 1; ++x) {
		TextHelper::gotoxy(xOffset + x, yOffset + Well::WELL_HEIGHT);
		cout << "=";
	}
}

/**
 * show the number of lines made
 */
void TextWellRenderer::showLines(int lines) {
	TextHelper::gotoxy(xOffsetScore, yOffsetScore);
	cout << "Lines: " << lines << "    ";
}

void TextWellRenderer::showTime(int secs) {
	TextHelper::gotoxy(xOffsetTime, yOffsetTime);
	cout << "Time: " << WellRenderer::formatTime(secs) << "    ";
}

void TextWellRenderer::renderElem(int elem) {

	// special logic for a ghost block
	bool ghost = elem > Block::NUM_BLOCKS;
	if (ghost) {
		elem -= Block::NUM_BLOCKS;
	}

	// default colours for any non-standard blocks which have been added
	// (e.g. through opponent making lines)
	int fgColour = TextHelper::DARK_GREY;
	int bgColour = TextHelper::DARK_GREY;

	// override the colours for standard blocks
	switch (elem) {
	case 0: // i.e. blank
		fgColour = bgColour = TextHelper::BLACK;
		break;
	case Block::Z:
		fgColour = bgColour = TextHelper::BRIGHT_RED;
		break;
	case 0 - Block::Z:
		fgColour = bgColour = TextHelper::RED;
		break;
	case Block::S:
		fgColour = bgColour = TextHelper::BRIGHT_GREEN;
		break;
	case 0 - Block::S:
		fgColour = bgColour = TextHelper::GREEN;
		break;
	case Block::T:
		fgColour = bgColour = TextHelper::BRIGHT_MAGENTA;
		break;
	case 0 - Block::T:
		fgColour = bgColour = TextHelper::MAGENTA;
		break;
	case Block::I:
		fgColour = bgColour = TextHelper::BRIGHT_CYAN;
		break;
	case 0 - Block::I:
		fgColour = bgColour = TextHelper::CYAN;
		break;
	case Block::L:
		// The L block should be orange according to the guidelines
		// but there isn't an orange option available
		fgColour = bgColour = TextHelper::WHITE;
		break;
	case 0 - Block::L:
		fgColour = bgColour = TextHelper::LIGHT_GREY;
		break;
	case Block::J:
		fgColour = bgColour = TextHelper::BRIGHT_BLUE;
		break;
	case 0 - Block::J:
		fgColour = bgColour = TextHelper::BLUE;
		break;
	case Block::O:
		fgColour = bgColour = TextHelper::BRIGHT_YELLOW;
		break;
	case 0 - Block::O:
		fgColour = bgColour = TextHelper::YELLOW;
		break;
	}

	// if it is a ghost block then we will just show [] in the particular colour
	if (ghost) {
		bgColour = TextHelper::BLACK;
	}

	TextHelper::setColours(bgColour, fgColour);
	cout << "[]";
	TextHelper::useDefaultColours();
}

