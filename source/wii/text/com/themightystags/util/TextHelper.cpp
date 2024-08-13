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

#include "com/themightystags/util/TextHelper.h"
#include <iostream>
#include <cstdio>

using com::themightystags::util::TextHelper;

void *TextHelper::xfb = NULL;
GXRModeObj *TextHelper::rmode = NULL;

/**
 * Use ANSI escape codes to go to the given coordinates
 */
void TextHelper::gotoxy(short x, short y) {
	printf("\x1b[%d;%dH", y, x);
}

/**
 * Use ANSI escape codes to set the colours
 */
void TextHelper::setColours(int bgColour, int fgColour) {
	printf("\x1b[%u;%um", 30 + (fgColour & 7), (fgColour & 8) == 8); // set foreground
	printf("\x1b[%u;%um", 40 + (bgColour & 7), (bgColour & 8) == 8); // set background
}

void TextHelper::useDefaultColours() {
	setColours(TextHelper::DEFAULT_BACKGROUND,
			TextHelper::DEFAULT_FOREGROUND);
}

void TextHelper::clearScreen() {
	printf("\x1b[2J");
}

bool TextHelper::init() {

	// Initialise the video system
	VIDEO_Init();

	// Obtain the preferred video mode from the system
	// This will correspond to the settings in the Wii menu
	rmode = VIDEO_GetPreferredMode(NULL);

	// Allocate memory for the display in the uncached region
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	// Initialise the console, required for printf
	console_init(xfb, 20, 20, rmode->fbWidth, rmode->xfbHeight, rmode->fbWidth
			* VI_DISPLAY_PIX_SZ);

	// Set up the video registers with the chosen mode
	VIDEO_Configure(rmode);

	// Tell the video hardware where our display memory is
	VIDEO_SetNextFramebuffer(xfb);

	// Make the display visible
	VIDEO_SetBlack(FALSE);

	// Flush the video register changes to the hardware
	VIDEO_Flush();

	// Wait for Video setup to complete
	VIDEO_WaitVSync();
	if (rmode->viTVMode & VI_NON_INTERLACE)
		VIDEO_WaitVSync();

	return true;
}
