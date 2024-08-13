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

#include "com/themightystags/toddtris/view/gx/GXWellRenderer.h"
#include "com/themightystags/toddtris/model/Block.h"
#include <fat.h>

using com::themightystags::toddtris::view::gx::GXWellRenderer;
using com::themightystags::toddtris::view::gx::GXScreenRenderer;
using com::themightystags::toddtris::model::Block;

bool GXWellRenderer::initialised = false;
GRRLIB_texImg *GXWellRenderer::tex_elem[8];
GRRLIB_texImg *GXWellRenderer::tex_surround;


GXWellRenderer::GXWellRenderer(WellPosition pos) : WellRenderer(false) {

	//initialise the class if required
	if (!GXWellRenderer::initialised) {
		init();
	}

	xOffset = 0;
	switch (pos) {
	case WellRenderer::Left:
		xOffset = 0;
		break;
	case WellRenderer::Centre:
		xOffset = 160;
		break;
	case WellRenderer::Right:
		xOffset = 320;
		break;
	}

	yOffset = 0;

	xOffsetSurround = xOffset + 2 * ELEM_WIDTH_PX;
	yOffsetSurround = yOffset + 64;

	xOffsetElem = xOffsetSurround + 15;
	yOffsetElem = yOffsetSurround;

	xOffsetNB = xOffsetSurround + SURROUND_WIDTH_PX + ELEM_WIDTH_PX;
	yOffsetNB = yOffsetSurround + (4 * ELEM_HEIGHT_PX);
	xOffsetScore = xOffsetNB;
	yOffsetScore = yOffsetNB + (6 * ELEM_HEIGHT_PX);
	xOffsetTime = xOffsetScore;
	yOffsetTime = yOffsetScore + (3 * ELEM_HEIGHT_PX);
	xOffsetHB = xOffsetNB;
	yOffsetHB = yOffsetTime + (2 * ELEM_HEIGHT_PX);
}

GXWellRenderer::~GXWellRenderer() {

}

/**
 * draw an element in the required place
 */
void GXWellRenderer::drawElem(int blockNum, int col, int row) {
	renderElem(blockNum, xOffsetElem + ELEM_WIDTH_PX * col, yOffsetElem
			+ ELEM_HEIGHT_PX * row, 0x00000099);
}

/**
 * display the next block
 */
void GXWellRenderer::showNext(const Block &block) {
	for (int x = 0; x < Block::MAX_BLOCK_SIZE; ++x) {
		for (int y = 0; y < Block::MAX_BLOCK_SIZE; ++y) {
			renderElem(block.getElem(x, y), xOffsetNB + ELEM_WIDTH_PX * x,
					yOffsetNB + ELEM_HEIGHT_PX * y, 0xFFFFFF00);
		}
	}
}

/**
 * display the hold block
 */
void GXWellRenderer::showHold(const Block *block) {
	for (int x = 0; x < Block::MAX_BLOCK_SIZE; ++x) {
		for (int y = 0; y < Block::MAX_BLOCK_SIZE; ++y) {
			int elem = (NULL == block) ? 0 : block->getElem(x,y);
			renderElem(elem, xOffsetHB + ELEM_WIDTH_PX * x,
					yOffsetHB + ELEM_HEIGHT_PX * y, 0xFFFFFF00);
		}
	}
}

/**
 * show the background image
 */
void GXWellRenderer::showWellSurround() {
	GRRLIB_DrawImg(xOffsetSurround, yOffsetSurround, tex_surround, 0, 1, 1, 0xFFFFFFFF);
}

/**
 * show the number of lines made
 */
void GXWellRenderer::showLines(int lines) {
	GXRenderer::renderInt(xOffsetScore,
			yOffsetScore,
			lines);
}

void GXWellRenderer::showTime(int secs) {
	GXRenderer::renderString(xOffsetTime,
			yOffsetTime,
			WellRenderer::formatTime(secs));
}

void GXWellRenderer::renderElem(int elem, int screenX, int screenY,
		u32 bgColour) {

	// if elem is not 0 then there is an element there
	if (elem) {
		// The different coloured elements are numbered from 1 or -1 but
		// indexed from 0 in the array of textures.
		int textureIndex = 0;
		u32 alpha = 0xFFFFFFFF; // no transparency

		if (elem < 0) {
			// the index of the texture we want is abs(elem) - 1 (zero indexed)
			textureIndex = -1 - elem;

			// this is a landed element so we will put a black square
			// behind it and then apply some transparency to the element,
			// thus darkening it
			alpha = 0xD2D2D2FF;
			GRRLIB_Rectangle(screenX, screenY, ELEM_WIDTH_PX, ELEM_HEIGHT_PX,
					0xFF000000, 1);

		} else if (elem > Block::NUM_BLOCKS) {
			// We subtract NUM_BLOCKS to find the corresponding element
			// We then subtract 1 to get the zero indexed value of textureIndex
			textureIndex = elem - Block::NUM_BLOCKS - 1;

			// this is a part of the ghost piece so we make it appear transparent
			alpha = 0x666666FF;

		} else {
			// this is the piece in play, just subtract 1 from elem to get the index
			// of the texture
			textureIndex = elem - 1;
		}
		// draw the element applying the alpha value chosen above
		GRRLIB_DrawImg(screenX, screenY, tex_elem[textureIndex], 0, 1, 1, alpha);
	} else {
		// empty element
		GRRLIB_Rectangle(screenX, screenY, ELEM_WIDTH_PX, ELEM_HEIGHT_PX,
				bgColour, 1);
	}
}

void GXWellRenderer::init() {

	// if already initialised then we should clean up
	if (initialised) {
		cleanup();
	}

	tex_surround = loadFileTexture("ttws.png");

	// load the element images
	int i;
	for (i = 1; i <= Block::NUM_BLOCKS; ++i) {
		char filename[20];
		sprintf(filename, "element%d.png", i);
		tex_elem[i - 1] = loadFileTexture(filename);
	}

	// load the dead element image
	tex_elem[i - 1] = loadFileTexture("deadelement.png");

	initialised = true;
}

void GXWellRenderer::cleanup() {
	if (initialised) {
		// free the well surround
		GRRLIB_FreeTexture(tex_surround);
		// free the element textures. <= NUM_BLOCKS to include the 'dead' block texture
		int i;
		for (i = 0; i <= Block::NUM_BLOCKS; ++i) {
			GRRLIB_FreeTexture(tex_elem[i]);
		}
		initialised = false;
	}
}

