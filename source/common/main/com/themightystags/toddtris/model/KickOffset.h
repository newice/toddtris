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
//  KickOffset.h
//  Implementation of the Class KickOffset
//  Created on:      07-Sept-2012
//  Original author: ToddA
//
// The KickOffset class is used in the implementation of 'wall kicks'.
// If an attempt to rotate a block fails (i.e. the rotated block does not fit
// at its current coordinates) then a series of small displacements of the
// block are attempted.
//
// For more details see http://harddrop.com/wiki/SRS .
//
///////////////////////////////////////////////////////////

#if !defined(KICKOFFSET__INCLUDED_)
#define KICKOFFSET__INCLUDED_

typedef int BaseElemsType[7][4][4];

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace model {
				class KickOffset {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					KickOffset(const KickOffset& object);
					KickOffset& operator=(const KickOffset& object);

				private:
					int x;
					int y;

				public:
					KickOffset(int x, int y);
					virtual ~KickOffset();
					int getX() const;
					int getY() const;
				};
			}
		}
	}
}
#endif // !defined(KICKOFFSET__INCLUDED_)
