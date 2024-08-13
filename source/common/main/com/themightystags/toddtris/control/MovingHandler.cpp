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
//  MovingHandler.cpp
//  Implementation of the Class MovingHandler
//  Created on:      18-Nov-2008 18:30:04
//  Original author: ToddA
//
//  See description in WellController.h
//
///////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/control/MovingHandler.h"

using com::themightystags::toddtris::control::MovingHandler;

// Need to create the instance here
MovingHandler MovingHandler::INSTANCE;

MovingHandler::MovingHandler() {
}

MovingHandler::~MovingHandler() {
}

MovingHandler &MovingHandler::getInstance() {
	return INSTANCE;
}

bool MovingHandler::rotate(Well &well) {
	return well.rotate();
}

bool MovingHandler::antirotate(Well &well) {
	return well.antirotate();
}

bool MovingHandler::left(Well &well) {
	return well.left();
}

bool MovingHandler::right(Well &well) {
	return well.right();
}

bool MovingHandler::down(Well &well) {
	return well.down();
}

bool MovingHandler::drop(Well &well) {
	return well.drop();
}

bool MovingHandler::hold(Well &well) {
	return well.hold();
}

void MovingHandler::restart(Well &well) {
	well.reset();
	well.startWell();
}

void MovingHandler::togglePause(Well &well) {
	well.stopWell();
}
