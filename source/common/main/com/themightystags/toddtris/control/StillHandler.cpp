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
//  StillHandler.cpp
//  Implementation of the Class StillHandler
//  Created on:      18-Nov-2008 19:33:47
//  Original author: ToddA
//
//  See description in WellController.h
//
///////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/control/StillHandler.h"

using com::themightystags::toddtris::control::StillHandler;

// Need to create the instance here
StillHandler StillHandler::INSTANCE;

StillHandler::StillHandler() {
}

StillHandler::~StillHandler() {

}

StillHandler &StillHandler::getInstance() {
	return INSTANCE;
}

bool StillHandler::rotate(Well &well) {
	return false;
}

bool StillHandler::antirotate(Well &well) {
	return false;
}

bool StillHandler::left(Well &well) {
	return false;
}

bool StillHandler::right(Well &well) {
	return false;
}

bool StillHandler::down(Well &well) {
	return false;
}

bool StillHandler::drop(Well &well) {
	return false;
}

bool StillHandler::hold(Well &well) {
	return false;
}

void StillHandler::restart(Well &well) {
	well.reset();
	well.startWell();
}

void StillHandler::togglePause(Well &well) {
	well.startWell();
}
