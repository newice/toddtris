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

//
//  See description in WellController.h
//

#include "com/themightystags/toddtris/control/Repeater.h"

using com::themightystags::toddtris::control::Repeater;
using com::themightystags::toddtris::control::LeftRepeater;
using com::themightystags::toddtris::control::RightRepeater;
using com::themightystags::toddtris::control::DownRepeater;

Repeater::Repeater(long firstPauseMs,
		long repeatPauseMs) :
	firstPauseMs(firstPauseMs), repeatPauseMs(repeatPauseMs),
			running(false) {
}

Repeater::~Repeater() {
}

void Repeater::start(ActionHandler &ah, Well &well) {
	timer.reset();
	timer.setTimeout(firstPauseMs);
	action(ah, well);
	running = true;
}

void Repeater::carryOn(ActionHandler &ah, Well &well) {
	if (running && timer.isTimeoutReached()) {
		action(ah, well);
		timer.setTimeout(repeatPauseMs);
	}
}

void Repeater::stop() {
	running = false;
}

LeftRepeater::LeftRepeater(long firstPauseMs, long repeatPauseMs) :
			Repeater(firstPauseMs, repeatPauseMs) {
	// nothing more to do
}

LeftRepeater::~LeftRepeater() {
}

void LeftRepeater::action(ActionHandler &ah, Well &well) {
	ah.left(well);
}

RightRepeater::RightRepeater(long firstPauseMs, long repeatPauseMs) :
	Repeater(firstPauseMs, repeatPauseMs) {
	// nothing more to do
}

RightRepeater::~RightRepeater() {
}

void RightRepeater::action(ActionHandler &ah, Well &well) {
	ah.right(well);
}

DownRepeater::DownRepeater(long firstPauseMs, long repeatPauseMs) :
	Repeater(firstPauseMs, repeatPauseMs) {
}

DownRepeater::~DownRepeater() {
}

void DownRepeater::action(ActionHandler &ah, Well &well) {
	ah.down(well);
}

