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

#ifndef GXOnePlayerRenderer_H
#define GXOnePlayerRenderer_H

#include "com/themightystags/toddtris/view/OnePlayerRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXScreenRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXWellRenderer.h"

using com::themightystags::toddtris::view::OnePlayerRenderer;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				namespace gx {
					class GXOnePlayerRenderer:
							public OnePlayerRenderer,
							public GXScreenRenderer {

					public:
						virtual ~GXOnePlayerRenderer();
						void render(const Well &well, bool full);
						void render(const Well &well,
								const vector<string> &options,
								int selectedIndex, bool full);
						static GXOnePlayerRenderer &getInstance();

					protected:
						WellRenderer &getWellRenderer();

					private:
						// the singleton instance of this class cannot be copied
						// and should be passed by reference
						GXOnePlayerRenderer();
						GXOnePlayerRenderer(const GXOnePlayerRenderer& object);
						GXOnePlayerRenderer& operator=(const GXOnePlayerRenderer& object);
						GXWellRenderer wellRenderer;
						static GXOnePlayerRenderer *INSTANCE;
						static bool initialised;
					};
				}
			}
		}
	}
}
#endif // GXOnePlayerRenderer_H
