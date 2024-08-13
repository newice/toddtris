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

#include <asndlib.h>
#include <mp3player.h>
#include <cstdlib>
#include <cstdio>

#include "com/themightystags/toddtris/sound/BGMPlayer.h"

using com::themightystags::toddtris::sound::BGMPlayer;

long BGMPlayer::lSize;
unsigned char * BGMPlayer::buffer;


void BGMPlayer::init(const string soundDir) {

	ASND_Init();
	MP3Player_Init();

	string filename = soundDir + "ttbgm.mp3";
	//char * filename = (char *)"sd:/sounds/ttbgm.mp3";
	FILE *fd = fopen(filename.c_str(), "rb");

	// obtain file size:
	fseek(fd , 0 , SEEK_END);
	lSize = ftell(fd);
	rewind(fd);

	// read the file
	buffer = (unsigned char*) malloc (sizeof(unsigned char)*lSize);;
	fread (buffer, 1, lSize, fd);
	fclose(fd);
}


void BGMPlayer::process() {
	if (!MP3Player_IsPlaying()){
		MP3Player_PlayBuffer(buffer,lSize,NULL);
	}
}

void BGMPlayer::end() {
	MP3Player_Stop();
	ASND_End();
}
