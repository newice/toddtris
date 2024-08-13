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

#ifndef GXSplashRenderer_H
#define GXSplashRenderer_H

#include "com/themightystags/toddtris/view/SplashRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXRenderer.h"
#include <grrlib.h>

using com::themightystags::toddtris::view::SplashRenderer;
using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				namespace gx {
					class GXSplashRenderer: public SplashRenderer, GXRenderer {
					public:
						GXSplashRenderer();
						virtual ~GXSplashRenderer();
						void render(bool full);
						static GXSplashRenderer &getInstance();
						static void cleanup();
						
					private:
						static void init();
						static GRRLIB_texImg *tex_splash;
						static GXSplashRenderer *INSTANCE;
						static bool initialised;
					};
				}
			}
		}
	}
}
#endif // GXSplashRenderer_H
