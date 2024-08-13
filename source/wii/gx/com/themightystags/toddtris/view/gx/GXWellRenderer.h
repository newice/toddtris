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

#if !defined(com_themightystags_toddtris_gx_GXWellRenderer)
#define com_themightystags_toddtris_gx_GXWellRenderer

#include "com/themightystags/toddtris/view/WellRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXScreenRenderer.h"
#include <grrlib.h>
#include <string>

using com::themightystags::toddtris::view::WellRenderer;
using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				namespace gx {
					class GXWellRenderer : public GXRenderer, public WellRenderer {//: public GXScreenRenderer, public WellRenderer {

					// instances of this class cannot be copied
					// and should be passed by reference
					private:
						GXWellRenderer(const GXWellRenderer& object);
						GXWellRenderer& operator=(const GXWellRenderer& object);
						static void init();

					public:
						GXWellRenderer(WellPosition pos);
						virtual ~GXWellRenderer();
						static void cleanup();

					protected:
						virtual void drawElem(int blockNum, int col, int row);
						virtual void showNext(const Block &block);
						virtual void showHold(const Block *block);
						virtual void showWellSurround();
						virtual void showLines(int lines);
						virtual void showTime(int secs);
						virtual void renderElem(int elem, int screenX,
								int screenY, u32 bgColour);

					private:
						int xOffset;
						int yOffset;
						int xOffsetSurround;
						int yOffsetSurround;
						int xOffsetElem;
						int yOffsetElem;
						int xOffsetNB;
						int yOffsetNB;
						int xOffsetScore;
						int yOffsetScore;
						int xOffsetTime;
						int yOffsetTime;
						int xOffsetHB;
						int yOffsetHB;
						const static int ELEM_WIDTH_PX = 16;
						const static int ELEM_HEIGHT_PX = 16;
						const static int SURROUND_WIDTH_PX = 192;
						const static int SURROUND_HEIGHT_PX = 312;
						static GRRLIB_texImg *tex_elem[8];
						static GRRLIB_texImg *tex_surround;
						static bool initialised;
					};
				}
			}
		}
	}
}
#endif // !defined(com_themightystags_toddtris_gx_GXWellRenderer)
