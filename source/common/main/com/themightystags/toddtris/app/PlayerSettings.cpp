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

#include "PlayerSettings.h"

using com::themightystags::toddtris::app::GameType;
using com::themightystags::toddtris::app::PlayerSettings;

PlayerSettings::PlayerSettings() : level(0), height(0), gameType(Marathon), upToDrop(false) {}

PlayerSettings::~PlayerSettings() {}

int PlayerSettings::getLevel() const {
	return level;
}

int PlayerSettings::getHeight() const {
	return height;
}

GameType PlayerSettings::getGameType() const {
	return gameType;
}

bool PlayerSettings::isUpToDrop() const {
	return upToDrop;
}

void PlayerSettings::incLevel() {
	if (level < MAX_LEVEL) {
		++level;
	}
}

void PlayerSettings::decLevel() {
	if (level > MIN_LEVEL) {
		--level;
	}
}

void PlayerSettings::incHeight() {
	if (height + HEIGHT_INCREMENT <= MAX_HEIGHT) {
		height += HEIGHT_INCREMENT;
	} else {
		height = MAX_HEIGHT;
	}
}

void PlayerSettings::decHeight() {
	if (height - HEIGHT_INCREMENT >= MIN_HEIGHT) {
		height -= HEIGHT_INCREMENT;
	} else {
		height = MIN_HEIGHT;
	}
}

void PlayerSettings::toggleGameType() {
	gameType = (gameType == Marathon) ? TimeTrial : Marathon;
}

void PlayerSettings::toggleUpToDrop() {
	upToDrop = !upToDrop;
}
