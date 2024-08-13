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
#include "com/themightystags/util/TimeHelper.h" // class's header file
#include <string>
#include <sstream>

using com::themightystags::toddtris::view::gx::GXRenderer;
using com::themightystags::util::TimeHelper;
using namespace std;

string GXRenderer::imageDir = "";
bool GXRenderer::initialised = false;
bool GXRenderer::screenshotRequested = false;
GRRLIB_ttfFont *GXRenderer::ttf_font1;
unsigned char *GXRenderer::ttf_font1_buffer;

GXRenderer::GXRenderer() {
	// check that the class is initialised
	if (!GXRenderer::initialised) {
		string err = "Error in GXRenderer::GXRenderer(). Class not initialised";
		throw err;
	}
}

GXRenderer::~GXRenderer() {}

void GXRenderer::init(const string &imageDir) {

	// if already initialised then we should clean up
	if (initialised) {
		cleanup();
	}

	// set the directory from which we'll load images and fonts
	GXRenderer::imageDir = imageDir;

	// load up the font from a file
	string fullPath = imageDir + "font1.ttf";
	FILE *fd = fopen(fullPath.c_str(), "rb");

	// obtain file size:
	fseek(fd , 0 , SEEK_END);
	long fileLength = ftell(fd);
	rewind(fd);

	// read the file
	ttf_font1_buffer = (unsigned char*) malloc (sizeof(unsigned char)*fileLength);
	fread(ttf_font1_buffer, sizeof(unsigned char), fileLength, fd);
	fclose(fd);

	ttf_font1 = GRRLIB_LoadTTF(ttf_font1_buffer, fileLength);

	initialised = true;
}


void GXRenderer::cleanup() {
	if (initialised) {
		GRRLIB_FreeTTF(ttf_font1);
		free(ttf_font1_buffer);
		initialised = false;
	}
}

GRRLIB_texImg *GXRenderer::loadFileTexture(const string &filename) {

	// We can't use GRRLIB_LoadTextureFromFile.  As of v4.3.2 this may fail
	// to correctly load a JPEG.  Instead we will read the file ourselves.
	string fullPath = imageDir + filename;
	FILE *fd = fopen(fullPath.c_str(), "rb");

	// obtain file size:
	fseek(fd , 0 , SEEK_END);
	long fileLength = ftell(fd);
	rewind(fd);

	// read the file
	unsigned char *buffer = (unsigned char*) malloc (sizeof(unsigned char)*fileLength);
	fread(buffer, sizeof(unsigned char), fileLength, fd);
	fclose(fd);

	// Load data into a texture.
	// If this is a JPEG then don't trust the GRRLIB_LoadTexture function.
	// It will call GRRLIB_LoadTextureJPG which may incorrectly identify
	// 0xFF 0xD9 as being the end of the file when it is just part of the data
	GRRLIB_texImg *tex;
	if (buffer[0]==0xFF && buffer[1]==0xD8 && buffer[2]==0xFF) {
		// This is a JPEG
		// Need to use the GRRLIB_LoadTextureJPGEx and tell it the size of
		// buffer rather than use GRRLIB_LoadTextureJPG which will guess the
		// size and may get it wrong
		tex = GRRLIB_LoadTextureJPGEx(buffer, (int)fileLength);
	} else {
		// Not a JPEG
		tex = GRRLIB_LoadTexture(buffer);
	}
	free(buffer);
	return tex;
}

void GXRenderer::videoSync() {
	// if a screenshot has been requested, then we take this before the video sync
	if (screenshotRequested) {
		screenshotRequested = false;
		stringstream sstm;
		sstm << imageDir << "screenshot_" << TimeHelper::currentTimeMilliseconds() << ".png";
		GRRLIB_ScrShot(sstm.str().c_str());
	}
	GRRLIB_Render();
}

void GXRenderer::requestScreenshot() {
	screenshotRequested = true;
}

void GXRenderer::renderMenuItem(const unsigned int xpos,
		const unsigned int ypos,
		const string &item,
		bool highlight,
		const unsigned int fontSize) {

	GRRLIB_Font *font = ttf_font1; // just here to make eclipse error go away
	GRRLIB_PrintfTTF(xpos + 3, ypos + 3, font, item.c_str(), fontSize, 0x000000FF);
	u32 fontColour = highlight ? 0x46FFFFFF : 0xFFFFFFFF; // : 0xFF777777;
	GRRLIB_PrintfTTF(xpos, ypos, font, item.c_str(), fontSize, fontColour);
}

void GXRenderer::renderString(const unsigned int xpos,
		const unsigned int ypos,
		const string &s,
		const unsigned int fontSize) {

	renderMenuItem(xpos, ypos, s, false, fontSize);
}

void GXRenderer::renderInt(const unsigned int xpos,
		const unsigned int ypos,
		const int i,
		const unsigned int fontSize) {

	char buffer[20];
	sprintf(buffer, "%d", i);
	renderString(xpos, ypos, buffer, fontSize);
}
