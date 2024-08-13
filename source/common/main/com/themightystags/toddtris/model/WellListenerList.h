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
//  WellListenerList.h
//  Implementation of the Class WellListenerList
//  Created on:      07-Nov-2008 19:19:31
//  Original author: ToddA
//
// WellListenerList the class used by Well to keep track of registered
// listeners.
///////////////////////////////////////////////////////////

#if !defined(EA_CDFA4A23_FF71_4c77_80E7_7089FE3FE1DC__INCLUDED_)
#define EA_CDFA4A23_FF71_4c77_80E7_7089FE3FE1DC__INCLUDED_

#include "com/themightystags/toddtris/model/WellListener.h"
#include <vector>

using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace model {
				class WellListenerList: public WellListener {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					WellListenerList(const WellListenerList& object);
					WellListenerList& operator=(const WellListenerList& object);

				private:
					vector<WellListener*> listeners;

				public:
					WellListenerList();
					virtual ~WellListenerList();
					void addListener(WellListener &listener);
					void wellChanged(const Well &well);
					void madeLines(const Well &well, int linesMade);
					void gameOver(const Well &well);
					void wellReset(const Well &well);
					void blockLanded(const Well &well);
					void complete(const Well &well);

				};
			}
		}
	}
}
#endif // !defined(EA_CDFA4A23_FF71_4c77_80E7_7089FE3FE1DC__INCLUDED_)
