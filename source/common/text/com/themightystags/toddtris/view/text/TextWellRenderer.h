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

#if !defined(com_themightystags_toddtris_text_TextWellRenderer)
#define com_themightystags_toddtris_text_TextWellRenderer

#include "com/themightystags/toddtris/view/WellRenderer.h"

using com::themightystags::toddtris::view::WellRenderer;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				namespace text {
					class TextWellRenderer: public WellRenderer {

					public:
						TextWellRenderer(WellPosition pos);
						virtual ~TextWellRenderer();

					protected:
						void drawElem(int blockNum, int col, int row);
						void showNext(const Block &block);
						void showHold(const Block *block);
						void showWellSurround();
						void showLines(int lines);
						void showTime(int secs);
						void renderElem(int elem);

					private:
						int xOffset;
						int yOffset;
						int xOffsetNB;
						int yOffsetNB;
						int xOffsetHB;
						int yOffsetHB;
						int xOffsetScore;
						int yOffsetScore;
						int xOffsetTime;
						int yOffsetTime;
						const static int ELEMENT_WIDTH = 2;
					};
				}
			}
		}
	}
}
#endif // !defined(com_themightystags_toddtris_text_TextWellRenderer)
