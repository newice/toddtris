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

///////////////////////////////////////////////////////////
//  WellRenderer.h
//  Implementation of the Class WellRenderer
//  Created on:      17-Nov-2008 14:04:43
//  Original author: ToddA
//
// WellRenderer is used by OnePlayerRenderer and TwoPlayerRenderer to render
// wells and associated detail on screen including the next block, time, and
// lines made.
//
///////////////////////////////////////////////////////////

#if !defined(EA_AE68027E_88D0_47b9_B38E_067D65843B24__INCLUDED_)
#define EA_AE68027E_88D0_47b9_B38E_067D65843B24__INCLUDED_

#include "com/themightystags/toddtris/model/Block.h"
#include "com/themightystags/toddtris/model/Well.h"
#include <string>

using com::themightystags::toddtris::model::Block;
using com::themightystags::toddtris::model::Well;
using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {

				class WellRenderer {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					WellRenderer(const WellRenderer& object);
					WellRenderer& operator=(const WellRenderer& object);

				public:
					enum WellPosition{Left, Centre, Right};
					WellRenderer(bool incremental);
					virtual ~WellRenderer();

					void render(const Well &well, bool full);
					void toggleGhost();

				protected:
					virtual void drawElem(int blockNum, int x, int y) = 0;
					virtual void showNext(const Block &block) = 0;
					virtual void showHold(const Block *block) = 0;
					virtual void showWellSurround() = 0;
					virtual void showLines(int lines) = 0;
					virtual void showTime(int secs) = 0;
					static string formatTime(int secs);

				private:
					/**
					 * the well, next block and lines as they appear on screen
					 */
					int screenWell[Well::WELL_WIDTH][Well::WELL_HEIGHT];
					bool incrementalUpdates;
					int screenLines;
					int screenTimeSecs;
					int screenNextBlockNum;
					int screenHoldBlockNum;
					bool showGhost;
				};
			}
		}
	}
}
#endif // !defined(EA_AE68027E_88D0_47b9_B38E_067D65843B24__INCLUDED_)
