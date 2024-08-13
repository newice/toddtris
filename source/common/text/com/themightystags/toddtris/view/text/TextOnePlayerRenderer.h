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

#ifndef TextOnePlayerRenderer_H
#define TextOnePlayerRenderer_H

#include "com/themightystags/toddtris/view/OnePlayerRenderer.h"
#include "com/themightystags/toddtris/view/text/TextWellRenderer.h"

using com::themightystags::toddtris::view::OnePlayerRenderer;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				namespace text {
					class TextOnePlayerRenderer:
							public OnePlayerRenderer {
					public:
						TextOnePlayerRenderer();
						virtual ~TextOnePlayerRenderer();
						void render(const Well &well, bool full);
						void render(const Well &well,
								const vector<string> &options,
								int selectedIndex, bool full);
						static TextOnePlayerRenderer &getInstance();

					protected:
						WellRenderer &getWellRenderer();

					private:
						TextWellRenderer wellRenderer;
						static TextOnePlayerRenderer *INSTANCE;
						static bool initialised;
						const vector<string> *renderedOptions;
						int renderedIndex;
					};
				}
			}
		}
	}
}
#endif // TextOnePlayerRenderer_H
