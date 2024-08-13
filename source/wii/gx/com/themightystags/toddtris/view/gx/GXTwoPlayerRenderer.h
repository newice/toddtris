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

#ifndef GXTwoPlayerRenderer_H
#define GXTwoPlayerRenderer_H

#include "com/themightystags/toddtris/view/TwoPlayerRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXScreenRenderer.h"
#include "com/themightystags/toddtris/view/gx/GXWellRenderer.h"

using com::themightystags::toddtris::view::TwoPlayerRenderer;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				namespace gx {
					class GXTwoPlayerRenderer:
							public TwoPlayerRenderer,
							public GXScreenRenderer {
					public:
						virtual ~GXTwoPlayerRenderer();
						void render(const Well &w0, const Well &w1,
								const TwoPlayerGame &tpg, bool full);
						void render(const Well &w0, const Well &w1,
								const TwoPlayerGame &tpg,
								const vector<string> &options,
								int selectedIndex, bool full);
						static GXTwoPlayerRenderer &getInstance();

					protected:
						WellRenderer &getWellRenderer(int index);

					private:
						// the singleton instance of this class cannot be copied
						// and should be passed by reference
						GXTwoPlayerRenderer();
						GXTwoPlayerRenderer(const GXTwoPlayerRenderer& object);
						GXTwoPlayerRenderer& operator=(const GXTwoPlayerRenderer& object);

						GXWellRenderer wellRenderer0;
						GXWellRenderer wellRenderer1;
						static GXTwoPlayerRenderer *INSTANCE;
						static bool initialised;
					};
				}
			}
		}
	}
}
#endif // GXTwoPlayerRenderer_H
