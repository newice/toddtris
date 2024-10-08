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

// Class automatically generated by Dev-C++ New Class wizard

#include "com/themightystags/util/Timer.h" // class's header file
#include "com/themightystags/util/TimeHelper.h"
using com::themightystags::util::Timer;
using com::themightystags::util::TimeHelper;

// class constructor
Timer::Timer() :
	fromTime(currentTime()), pauseTime(0), isPaused(false),
			isTimeoutSet(false), timeoutTime(0) {

	// nothing more to do
}

// class destructor
Timer::~Timer() {
}

void Timer::reset() {
	fromTime = currentTime();
	isPaused = false;
	isTimeoutSet = false;
}

long Timer::getElapsedMilliseconds() const {
	return isPaused ? (pauseTime - fromTime) : (currentTime() - fromTime);
}

void Timer::pause() {
	if (!isPaused) {
		pauseTime = currentTime();
		isPaused = true;
	}
}

void Timer::unPause() {
	// adjust the fromTime and timeoutTime to account for the time spent paused
	if (isPaused) {
		long pauseDuration = currentTime() - pauseTime;
		fromTime += pauseDuration;
		timeoutTime += pauseDuration;
		isPaused = false;
	}
}

bool Timer::isTimeoutReached() const {
	if (isPaused) {
		return (isTimeoutSet && (pauseTime > timeoutTime));
	} else {
		return (isTimeoutSet && (currentTime() > timeoutTime));
	}
}

void Timer::setTimeout(long ms) {
	if (isPaused) {
		// if the timer is paused, set the timeout time based on the paused time
		// this will then be updated when the well is unpaused
		timeoutTime = pauseTime + ms;
	} else {
		timeoutTime = currentTime() + ms;
	}
	isTimeoutSet = true;
}

long Timer::currentTime() {
	return TimeHelper::currentTimeMilliseconds();
}
