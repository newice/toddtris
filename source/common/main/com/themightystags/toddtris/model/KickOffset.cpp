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
//  KickOffset.cpp
//  Implementation of the Class KickOffset
//  Created on:      07-Sept-2012
//  Original author: ToddA
//
//  See KickOffset.h for description
//
///////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/model/KickOffset.h"

using com::themightystags::toddtris::model::KickOffset;

KickOffset::KickOffset(int x, int y) :
	x(x), y(y) {
}

KickOffset::~KickOffset() {
	// nothing to do
}

int KickOffset::getX() const {
	return x;
}

int KickOffset::getY() const {
	return y;
}
