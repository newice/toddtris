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
//  Randomizer.h
//  Implementation of the Class Randomizer
//  Created on:      17-Jul-2009
//  Original author: ToddA
//
// Randomizer is a pure virtual class is used by the Well class to select
// blocks at random.  Several different algorithms are implemented.
//
///////////////////////////////////////////////////////////

#if !defined(RANDOMIZER_H)
#define RANDOMIZER_H

#include <deque>
#include <vector>
using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace model {
				class Randomizer {
				public:
					Randomizer();
					virtual ~Randomizer();
					virtual void reset() = 0;
					virtual int getBlockNum() = 0;
					static Randomizer *newDefaultRandomizer();
				};

				class SimpleRandomizer : public Randomizer {
				public:
					SimpleRandomizer();
					~SimpleRandomizer();
					void reset();
					int getBlockNum();
				};

				class AbstractTgmRandomizer : public Randomizer {
				private:
					int maxTries;
					int next;
					deque<int> history;
					bool inHistory(const int blockNum);
					void historyPop();
				protected:
					void historyPush(int blockNum);
					virtual void prefillHistory() = 0;
				public:
					AbstractTgmRandomizer(int maxTries);
					~AbstractTgmRandomizer();
					void reset();
					int getBlockNum();
				};

				class Tgm1Randomizer : public AbstractTgmRandomizer {
				protected:
					void prefillHistory();
				public:
					Tgm1Randomizer();
					~Tgm1Randomizer();
				};

				class Tgm2Randomizer : public AbstractTgmRandomizer {
				protected:
					void prefillHistory();
				public:
					Tgm2Randomizer();
					~Tgm2Randomizer();
				};

				class TtcRandomizer : public Randomizer {
				protected:
					vector<int> sequence;
					vector<int>::iterator sequenceIter;
				public:
					TtcRandomizer();
					~TtcRandomizer();
					void reset();
					int getBlockNum();
				};
			}
		}
	}
}
#endif // !defined(RANDOMIZER_H)
