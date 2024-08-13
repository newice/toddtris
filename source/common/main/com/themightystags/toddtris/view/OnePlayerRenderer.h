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

////////////////////////////////////////////////////////////////////////////////
// Used to draw the screen for a one player game that may be in-play, paused or
// game over.
////////////////////////////////////////////////////////////////////////////////
#ifndef OnePlayerRenderer_H
#define OnePlayerRenderer_H

#include "com/themightystags/toddtris/model/Well.h"
#include "com/themightystags/toddtris/view/WellRenderer.h"

using com::themightystags::toddtris::model::Well;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				class OnePlayerRenderer {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					OnePlayerRenderer(const OnePlayerRenderer& object);
					OnePlayerRenderer& operator=(const OnePlayerRenderer& object);

				protected:
					virtual WellRenderer &getWellRenderer() = 0;

				public:
					OnePlayerRenderer();
					virtual ~OnePlayerRenderer();
					void toggleGhost();
					virtual void render(const Well &well, bool full) = 0;
					virtual void render(const Well &well,
							const vector<string> &options,
							int selectedIndex, bool full) = 0;
				};
			}
		}
	}
}
#endif // OnePlayerRenderer_H
