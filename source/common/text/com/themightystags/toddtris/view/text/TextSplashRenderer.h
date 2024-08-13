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

#ifndef TextSplashRenderer_H
#define TextSplashRenderer_H

#include "com/themightystags/toddtris/view/SplashRenderer.h"
#include <string>

using com::themightystags::toddtris::view::SplashRenderer;
using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				namespace text {
					class TextSplashRenderer: public SplashRenderer {
					public:
						TextSplashRenderer();
						virtual ~TextSplashRenderer();
						void render(bool full);
						static TextSplashRenderer &getInstance();
						
					private:
						static TextSplashRenderer *INSTANCE;
						static bool initialised;
						static const int LOGO_HEIGHT = 5;
						static const string LOGO[LOGO_HEIGHT];
					};
				}
			}
		}
	}
}
#endif // TextSplashRenderer_H
