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
//  Well.h
//  Implementation of the Class Well
//  Created on:      07-Nov-2008 19:19:12
//  Original author: ToddA
//
// 'Well' is the most important class in the toddtris game.
// This class represents the well into which pieces are dropped, the blocks
// that have already landed, the block currently in play, the 'next' block and
// the 'ghost' block.  The 'ghost' block shows the position in which the block
// would land if dropped from current position.
//
// Methods are included to rotate and move the in-play block, display or hide
// the 'ghost' block, add lines to the bottom of the Well for use in two player
// games and to store or use the 'hold' block (note that the hold block facility
// is disabled by not being connected to any input as the author does not like
// this facility).
//
// The arrangement of elements in the well is implemented by using a
// two dimensional array to denoting the 'landed' elements and the (x, y)
// coordinates of the in-play block.  The 'getElem' method overlays the in-play
// block onto the well to give a snapshot view of the state of the current state
// of the well.
///////////////////////////////////////////////////////////

#if !defined(EA_A853581C_BFC4_4e6a_8F14_1F6021E7496E__INCLUDED_)
#define EA_A853581C_BFC4_4e6a_8F14_1F6021E7496E__INCLUDED_

#include "com/themightystags/toddtris/model/Block.h"
#include "com/themightystags/toddtris/model/WellListener.h"
#include "com/themightystags/toddtris/model/WellListenerList.h"
#include "com/themightystags/toddtris/model/Randomizer.h"
#include "com/themightystags/util/Timer.h"

using com::themightystags::util::Timer;
using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace model {

				class Well {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					Well(const Well& object);
					Well& operator=(const Well& object);

				public:
					enum WellState {newlyReset, playing, stopped, gameOver, complete};

				public:
					static const int WELL_WIDTH = 10;
					static const int WELL_HEIGHT = 20;

				private:
					static const int HIDDEN_ROWS = 4;
					static const int FULL_WELL_HEIGHT = WELL_HEIGHT
							+ HIDDEN_ROWS;

					/**
					 * Blocks used as reference for next block and
					 * hold block
					 */
					static Block **refBlockList;

					Block *block;

					/**
					 * list of all listeners
					 */
					WellListenerList listenerList;

					/**
					 * The contents of the well which have been landed
					 */
					int deadElems[WELL_WIDTH][FULL_WELL_HEIGHT];

					int blockX;
					int blockY;
					int ghostY;

					int lines;

					WellState wellState;
					Timer timer;

					/**
					 * The target number of lines
					 */
					int targetLines;

					/**
					 * The height of the randomly placed blocks when the well is reset
					 */
					int startHeight;

					int level;

					/**
					 * Is wall kicking enabled?
					 */
					bool useKicks;

					int nextBlockNum;

					/**
					 * Index of the 'hold' block or -1 if there is no hold piece
					 */
					int holdBlockNum;

					/**
					 * Is the user allowed to use the hold facility?
					 * Once used, hold cannot be used again until the block
					 * has fallen
					 */
					bool holdAllowed;

					/**
					 * private final Block blockList[];
					 */
					Block **blockList;

					Randomizer *randomizer;

				public:
					Well(int targetLines, int startHeight, int level, bool useKicks = true);
					virtual ~Well();

					void updateChallengeSettings(int targetLines,
							int startHeight, int level);
					int getTargetLines() const;
					int getLevel() const;
					void reset();
					void addListener(WellListener &listener);
					void startWell();
					void stopWell();
					int getRunningTimeInSeconds() const;

					// TODO change these methods to getState and add callbacks?
					bool isComplete() const;
					bool isMoving() const;
					bool isGameOver() const;
					int getElem(int viewX, int viewY) const;
					int getLines() const;
					int getRemainingLines() const;
					const Block &getNextBlock() const;
					const Block *getHoldBlock() const;
					int getStartHeight() const;
					bool left();
					bool right();
					bool rotate();
					bool antirotate();
					bool down();
					bool drop();
					bool hold();
					int getStackHeight() const;
					void addLine(int blankCol);
					void process();
					WellState getWellState() const;
					void wellChanged();

				private:
					void setStartHeight(int sh);
					bool blockDown();
					bool landBlock();
					bool checkEmpty(const Block &b, int x, int y) const;
					void putDeadBlock();
					void removeLine(int l);
					bool lineFull(int l) const;
					int checkLines();
					void incLines(int l);
					bool newBlock();
					bool setBlock(int blockNum);
					void setGameOverState();
					int getRandomBlockNum();
					static Block **createBlockList();
				};
			}
		}
	}
}
#endif // !defined(EA_A853581C_BFC4_4e6a_8F14_1F6021E7496E__INCLUDED_)
