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

#if !defined(com_themightystags_util_TextHelper)
#define com_themightystags_util_TextHelper

#include <gccore.h>
using namespace std;

namespace com {
	namespace themightystags {
		namespace util {
			class TextHelper {
			private:
				// This class cannot be instantiated
				TextHelper();
				static void *xfb;
				static GXRModeObj *rmode;

			public:
				static bool init();
				static void gotoxy(short x, short y);
				static void setColours(int bgColour, int fgColour);
				static void useDefaultColours();
				static void clearScreen();

				static const int BLACK = 0;
				static const int RED = 1;
				static const int GREEN = 2;
				static const int YELLOW = 3;
				static const int BLUE = 4;
				static const int MAGENTA = 5;
				static const int CYAN = 6;
				static const int LIGHT_GREY = 7;
				static const int DARK_GREY = 8;
				static const int BRIGHT_RED = 9;
				static const int BRIGHT_GREEN = 10;
				static const int BRIGHT_YELLOW = 11;
				static const int BRIGHT_BLUE = 12;
				static const int BRIGHT_MAGENTA = 13;
				static const int BRIGHT_CYAN = 14;
				static const int WHITE = 15;

				static const int DEFAULT_BACKGROUND = BLACK;
				static const int DEFAULT_FOREGROUND = WHITE;
			};
		}
	}
}
#endif // !defined(com_themightystags_util_TextHelper)
