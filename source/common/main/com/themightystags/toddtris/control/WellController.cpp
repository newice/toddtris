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
//  WellController.cpp
//  Implementation of the Class WellController
//  Created on:      18-Nov-2008 18:56:42
//  Original author: ToddA
//
//  See WellController.h for detailed description
//
///////////////////////////////////////////////////////////

#include "com/themightystags/toddtris/control/WellController.h"
#include "com/themightystags/toddtris/control/MovingHandler.h"
#include "com/themightystags/toddtris/control/MovingHandler.h"
#include "com/themightystags/toddtris/control/StillHandler.h"

using com::themightystags::toddtris::control::WellController;
using com::themightystags::toddtris::control::ActionHandler;
using com::themightystags::toddtris::model::Well;
using com::themightystags::toddtris::control::StillHandler;
using com::themightystags::toddtris::control::ActionHandler;

WellController::WellController(Well &well) :
	well(well), leftRepeater(LEFT_RIGHT_FIRST_PAUSE_MS,
			LEFT_RIGHT_REPEAT_PAUSE_MS), rightRepeater(
			LEFT_RIGHT_FIRST_PAUSE_MS, LEFT_RIGHT_REPEAT_PAUSE_MS),
			downRepeater(DOWN_PAUSE_MS, DOWN_PAUSE_MS) {

	well.addListener(*this);
}

WellController::~WellController() {
}

bool WellController::rotate() {
	return getHandler().rotate(well);
}

bool WellController::antirotate() {
	return getHandler().antirotate(well);
}

void WellController::leftPressed() {
	leftRepeater.start(getHandler(), well);
}

void WellController::leftHeld() {
	leftRepeater.carryOn(getHandler(), well);
}

void WellController::rightPressed() {
	rightRepeater.start(getHandler(), well);
}

void WellController::rightHeld() {
	rightRepeater.carryOn(getHandler(), well);
}

void WellController::downPressed() {
	downRepeater.start(getHandler(), well);
}

void WellController::downHeld() {
	downRepeater.carryOn(getHandler(), well);
}

bool WellController::drop() {
	return getHandler().drop(well);
}

bool WellController::hold() {
	return getHandler().hold(well);
}

void WellController::restart() {
	getHandler().restart(well);
}

void WellController::togglePause() {
	getHandler().togglePause(well);
}

/**
 * Callback method used to stop the down repeater when a block lands
 */
void WellController::blockLanded(const Well &well) {
	downRepeater.stop();
}

ActionHandler &WellController::getHandler() {
	if (well.isMoving()) {
		return MovingHandler::getInstance();
	} else {
		return StillHandler::getInstance();
	}
}
