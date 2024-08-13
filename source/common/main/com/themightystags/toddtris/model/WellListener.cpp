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
//  WellListener.cpp
//  Implementation of the Interface WellListener
//  Created on:      07-Nov-2008 19:20:14
//  Original author: ToddA
//
//  See WellListener.h for description
///////////////////////////////////////////////////////////
#include "com/themightystags/toddtris/model/Well.h"

using com::themightystags::toddtris::model::WellListener;

WellListener::WellListener() {

}

WellListener::~WellListener() {

}

void WellListener::wellChanged(const Well &well) {
	// do nothing
}

void WellListener::madeLines(const Well &well, int linesMade) {
	// do nothing
}

void WellListener::gameOver(const Well &well) {
	// do nothing
}

void WellListener::wellReset(const Well &well) {
	// do nothing
}

void WellListener::blockLanded(const Well &well) {
	// do nothing
}

void WellListener::complete(const Well &well) {
	// do nothing
}
