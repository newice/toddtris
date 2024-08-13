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
//  WellRenderer.cpp
//  Implementation of the Class WellRenderer
//  Created on:      17-Nov-2008 14:04:44
//  Original author: ToddA
//
// See WellRenderer.h for description
//
///////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/view/WellRenderer.h"
#include <sstream>

using com::themightystags::toddtris::view::WellRenderer;

WellRenderer::WellRenderer(bool incremental) :
		incrementalUpdates(incremental), screenLines(-1), screenTimeSecs(-1),
			screenNextBlockNum(0), screenHoldBlockNum(0), showGhost(false) {

	for (int i = 0; i < Well::WELL_WIDTH; i++) {
		for (int j = 0; j < Well::WELL_HEIGHT; j++) {
			screenWell[i][j] = -99;
		}
	}
}

WellRenderer::~WellRenderer() {

}

string WellRenderer::formatTime(int secs) {
	stringstream timess;
	int remainderSecs = secs%60;
	int mins = secs / 60;
	timess << mins << ":";
	if (remainderSecs < 10) {
		timess << "0";
	}
	timess << remainderSecs;
	return timess.str();
}

void WellRenderer::toggleGhost() {
	showGhost = !showGhost;
}

/**
 * draw
 */
void WellRenderer::render(const Well &well, bool full) {

	bool redraw = full || !incrementalUpdates;

	if (redraw) {
		showWellSurround();
	}

	const Block &nextBlock = well.getNextBlock();
	const int nextBlockNum = nextBlock.getBlockNum();
	if (redraw || (screenNextBlockNum != nextBlockNum)) {
		showNext(nextBlock);
		screenNextBlockNum = nextBlockNum;
	}

	const Block *holdBlock = well.getHoldBlock();
	const int holdBlockNum = (NULL == holdBlock) ? 0 : holdBlock->getBlockNum();
	if (redraw || (screenHoldBlockNum != holdBlockNum)) {
		showHold(holdBlock);
		screenHoldBlockNum = holdBlockNum;
	}

	int lines = (well.getTargetLines() == 0) ? well.getLines()
			: well.getRemainingLines();
	if (redraw || screenLines != lines) {
		showLines(lines);
		screenLines = lines;
	}

	int timeSecs = well.getRunningTimeInSeconds();
	if (redraw || timeSecs != screenTimeSecs) {
		showTime(timeSecs);
		screenTimeSecs = timeSecs;
	}

	for (int i = 0; i < Well::WELL_WIDTH; i++) {
		for (int j = 0; j < Well::WELL_HEIGHT; j++) {
			int elem = well.getElem(i, j);
			if (!showGhost && elem > Block::NUM_BLOCKS) {
				elem = 0;
			}
			if (redraw || elem != screenWell[i][j]) {
				drawElem(elem, i, j);
				screenWell[i][j] = elem;
			}
		}
	}
}

