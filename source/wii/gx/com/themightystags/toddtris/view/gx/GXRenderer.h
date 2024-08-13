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

#if !defined(com_themightystags_toddtris_gx_GXRenderer)
#define com_themightystags_toddtris_gx_GXRenderer

#include <grrlib.h>
#include <string>

using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				namespace gx {

					class GXRenderer {

					// instances of this class cannot be copied
					// and should be passed by reference
					private:
						GXRenderer(const GXRenderer& object);
						GXRenderer& operator=(const GXRenderer& object);

					public:
						virtual ~GXRenderer();
						static void init(const string &imageDir);
						static void cleanup();
						static void videoSync();
						static void requestScreenshot();
						static void renderMenuItem(
								const unsigned int xpos,
								const unsigned int ypos,
								const string &item,
								const bool highlight,
								const unsigned int fontSize = 28);

						static void renderString(
								const unsigned int xpos,
								const unsigned int ypos,
								const string &s,
								const unsigned int fontSize = 28);

						static void renderInt(
								const unsigned int xpos,
								const unsigned int ypos,
								const int i,
								const unsigned int fontSize = 28);

						static GRRLIB_texImg *loadFileTexture(const string &filename);

					protected:
						GXRenderer();

					private:
						static string imageDir;
						static bool initialised;
						static GRRLIB_ttfFont *ttf_font1;
						static unsigned char *ttf_font1_buffer;
						static bool screenshotRequested;
					};
				}
			}
		}
	}
}
#endif // !defined(com_themightystags_toddtris_gx_GXRenderer)
