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
//  WellListener.h
//  Implementation of the Interface WellListener
//  Created on:      07-Nov-2008 19:20:14
//  Original author: ToddA
//
// WellListener is a pure virtual class which may be extended by classes
// wishing to be notified of changes to the state of a well through various
// callback methods.  For example the TwoPlayerGame class extends WellListener
// so that it can be notified of lines made by each player adding lines to the
// other player's well in response.
// The Well::addListener method is used to register listeners.
///////////////////////////////////////////////////////////

#if !defined(EA_D2AED4FB_6F8D_45cf_BEC7_1506A4C6E364__INCLUDED_)
#define EA_D2AED4FB_6F8D_45cf_BEC7_1506A4C6E364__INCLUDED_

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace model {
				class Well;

				class WellListener {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					WellListener(const WellListener& object);
					WellListener& operator=(const WellListener& object);

				public:

					virtual ~WellListener();
					virtual void wellChanged(const Well &well);
					virtual void madeLines(const Well &well, int linesMade);
					virtual void gameOver(const Well &well);
					virtual void wellReset(const Well &well);
					virtual void blockLanded(const Well &well);
					virtual void complete(const Well &well);

				protected:
					WellListener();

				};
			}
		}
	}
}
#endif // !defined(EA_D2AED4FB_6F8D_45cf_BEC7_1506A4C6E364__INCLUDED_)
