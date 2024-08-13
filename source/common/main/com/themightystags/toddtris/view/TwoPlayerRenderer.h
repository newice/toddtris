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
// Used to draw the screen for a two player game that may be in-play, paused or
// game over.
////////////////////////////////////////////////////////////////////////////////
#ifndef TwoPlayerRenderer_H
#define TwoPlayerRenderer_H

#include "com/themightystags/toddtris/model/Well.h"
#include "com/themightystags/toddtris/model/TwoPlayerGame.h"
#include "com/themightystags/toddtris/view/WellRenderer.h"

using com::themightystags::toddtris::model::Well;
using com::themightystags::toddtris::model::TwoPlayerGame;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				class TwoPlayerRenderer {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					TwoPlayerRenderer(const TwoPlayerRenderer& object);
					TwoPlayerRenderer& operator=(const TwoPlayerRenderer& object);

				protected:
					virtual WellRenderer &getWellRenderer(int index) = 0;

				public:
					TwoPlayerRenderer();
					virtual ~TwoPlayerRenderer();
					void toggleGhost(int index);
					virtual void render(const Well &w0, const Well &w1,
							const TwoPlayerGame &tpg, bool full) = 0;
					virtual void render(const Well &w0, const Well &w1,
							const TwoPlayerGame &tpg,
							const vector<string> &options,
							int selectedIndex, bool full) = 0;
				};
			}
		}
	}
}
#endif // TwoPlayerRenderer_H
