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

using com::themightystags::util::TextHelper;


const HANDLE TextHelper::hOut = GetStdHandle(STD_OUTPUT_HANDLE);

void TextHelper::gotoxy ( short x, short y ){
	COORD coord = {x, y};
	SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord );
}


void TextHelper::setColours (int bgColour, int fgColour){

    WORD colours = 0;

    switch (bgColour) {
    case TextHelper::BLACK :
        //nothing to do
        break;
    case TextHelper::DARK_GREY:
    	colours |=  BACKGROUND_INTENSITY;
        break;
    case TextHelper::RED :
        colours |= BACKGROUND_RED;
        break;
    case TextHelper::BRIGHT_RED :
        colours |= BACKGROUND_RED | BACKGROUND_INTENSITY;
        break;
    case TextHelper::GREEN :
        colours |= BACKGROUND_GREEN;
        break;
    case TextHelper::BRIGHT_GREEN :
        colours |= BACKGROUND_GREEN | BACKGROUND_INTENSITY;
        break;
    case TextHelper::YELLOW :
        colours |= BACKGROUND_GREEN | BACKGROUND_RED;
        break;
    case TextHelper::BRIGHT_YELLOW :
        colours |= BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
        break;
    case TextHelper::BLUE :
        colours |= BACKGROUND_BLUE;
        break;
    case TextHelper::BRIGHT_BLUE :
        colours |= BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        break;
    case TextHelper::MAGENTA :
        colours |= BACKGROUND_RED | BACKGROUND_BLUE;
        break;
    case TextHelper::BRIGHT_MAGENTA :
        colours |= BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        break;
    case TextHelper::CYAN :
        colours |= BACKGROUND_BLUE | BACKGROUND_GREEN;
        break;
    case TextHelper::BRIGHT_CYAN :
        colours |= BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
        break;
    case TextHelper::LIGHT_GREY :
        colours |= BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
        break;
    case TextHelper::WHITE :
        colours |= BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        break;
    }

    switch (fgColour) {
    case TextHelper::BLACK :
        //nothing to do
        break;
    case TextHelper::DARK_GREY:
    	colours |=  FOREGROUND_INTENSITY;
        break;
    case TextHelper::RED :
        colours |= FOREGROUND_RED;
        break;
    case TextHelper::BRIGHT_RED :
        colours |= FOREGROUND_RED | FOREGROUND_INTENSITY;
        break;
    case TextHelper::GREEN :
        colours |= FOREGROUND_GREEN;
        break;
    case TextHelper::BRIGHT_GREEN :
        colours |= FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        break;
    case TextHelper::YELLOW :
        colours |= FOREGROUND_GREEN | FOREGROUND_RED;
        break;
    case TextHelper::BRIGHT_YELLOW :
        colours |= FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
        break;
    case TextHelper::BLUE :
        colours |= FOREGROUND_BLUE;
        break;
    case TextHelper::BRIGHT_BLUE :
        colours |= FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        break;
    case TextHelper::MAGENTA :
        colours |= FOREGROUND_RED | FOREGROUND_BLUE;
        break;
    case TextHelper::BRIGHT_MAGENTA :
        colours |= FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        break;
    case TextHelper::CYAN :
        colours |= FOREGROUND_BLUE | FOREGROUND_GREEN;
        break;
    case TextHelper::BRIGHT_CYAN :
        colours |= FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        break;
    case TextHelper::LIGHT_GREY :
        colours |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        break;
    case TextHelper::WHITE :
        colours |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        break;
    }

    SetConsoleTextAttribute(hOut, colours);
}

void TextHelper::useDefaultColours() {
	setColours(TextHelper::DEFAULT_BACKGROUND,
			TextHelper::DEFAULT_FOREGROUND);
}

void TextHelper::clearScreen() {
    system("cls");
}

void TextHelper::init() {
    // nothing to do
}

