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

#ifndef GXMenuRenderer_H
#define GXMenuRenderer_H

#include "com/themightystags/toddtris/view/MenuRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXScreenRenderer.h"

#include <grrlib.h>
#include <string>

using com::themightystags::toddtris::view::MenuRenderer;
using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				namespace gx {
					class GXMenuRenderer: public MenuRenderer, public GXScreenRenderer {

					// instances of this class cannot be copied
					// and should be passed by reference
					private:
						GXMenuRenderer(const GXMenuRenderer& object);
						GXMenuRenderer& operator=(const GXMenuRenderer& object);

					public:
						virtual ~GXMenuRenderer();
						void render(const vector<string> &options,
								const vector<bool> &selected, bool full);
						static GXMenuRenderer &getInstance();

					private:
						GXMenuRenderer();
						static GXMenuRenderer *INSTANCE;
						static bool initialised;
					};
				}
			}
		}
	}
}
#endif // GXMenuRenderer_H
