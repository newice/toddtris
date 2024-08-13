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
//  WellListenerList.cpp
//  Implementation of the Class WellListenerList
//  Created on:      07-Nov-2008 19:19:32
//  Original author: ToddA
//
//  See WellListenerList.h for description
///////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/model/Well.h"

using com::themightystags::toddtris::model::WellListenerList;

WellListenerList::WellListenerList() {

}

WellListenerList::~WellListenerList() {

}

void WellListenerList::addListener(WellListener &listener) {
	listeners.push_back(&listener);
}

void WellListenerList::wellChanged(const Well &well) {
	for (unsigned int i = 0; i < listeners.size(); ++i) {
		listeners[i]->wellChanged(well);
	}
}

void WellListenerList::madeLines(const Well &well, int linesMade) {
	for (unsigned int i = 0; i < listeners.size(); ++i) {
		listeners[i]->madeLines(well, linesMade);
	}
}

void WellListenerList::gameOver(const Well &well) {
	for (unsigned int i = 0; i < listeners.size(); ++i) {
		listeners[i]->gameOver(well);
	}
}

void WellListenerList::wellReset(const Well &well) {
	for (unsigned int i = 0; i < listeners.size(); ++i) {
		listeners[i]->wellReset(well);
	}
}

void WellListenerList::blockLanded(const Well &well) {
	for (unsigned int i = 0; i < listeners.size(); ++i) {
		listeners[i]->blockLanded(well);
	}
}

void WellListenerList::complete(const Well &well) {
	for (unsigned int i = 0; i < listeners.size(); ++i) {
		listeners[i]->complete(well);
	}
}
