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
//  TwoPlayerGame.h
//  Implementation of the Class TwoPlayerGame
//  Original author: ToddA
//
// The TwoPlayerGame class is used to model a two player battle.  Lines made by
// each player are tracked and result in lines being added to the bottom of the
// opposing player's well.
// The number of games won by each player is also tracked.
///////////////////////////////////////////////////////////

#if !defined(com_themightystags_toddtris_model_twoplayergame)
#define com_themightystags_toddtris_model_twoplayergame

#include "com/themightystags/toddtris/model/WellListener.h"
#include "com/themightystags/toddtris/model/Well.h"

using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace model {
				class TwoPlayerGame: public WellListener {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					TwoPlayerGame(const TwoPlayerGame& object);
					TwoPlayerGame& operator=(const TwoPlayerGame& object);

				private:
					Well &well0;
					Well &well1;
					int linesOwing;
					int blankCol;

				public:
					TwoPlayerGame(Well &w0, Well &w1);
					virtual ~TwoPlayerGame();

					void pause();
					void resume();
					void playAgain();
					void newGame();
					int getScore(unsigned int playerIndex) const;

					/** call back WellListener methods */
					void madeLines(const Well &well, int linesMade);
					void gameOver(const Well &well);
					void wellReset(const Well &well);
					void blockLanded(const Well &well);

				private:
					int scores[2];
				};
			}
		}
	}
}
#endif // !defined(com_themightystags_toddtris_model_twoplayergame)
