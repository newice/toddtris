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

#ifndef PlayerSettings_H
#define PlayerSettings_H

#include "com/themightystags/toddtris/model/Well.h"

using com::themightystags::toddtris::model::Well;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {

				enum GameType {Marathon, TimeTrial};

				class PlayerSettings {
				public:
					static const int MIN_LEVEL = 0;
					static const int MAX_LEVEL = 15;
					static const int MIN_HEIGHT = 0;
					static const int MAX_HEIGHT = Well::WELL_HEIGHT - 3;
					static const int HEIGHT_INCREMENT = 1;

					PlayerSettings();
					~PlayerSettings();
					int getLevel() const;
					int getHeight() const;
					GameType getGameType() const;
					bool isUpToDrop() const;
					void incLevel();
					void decLevel();
					void incHeight();
					void decHeight();
					void toggleGameType();
					void toggleUpToDrop();

				private:
					int level;
					int height;
					GameType gameType;
					bool upToDrop;
				};
			}
		}
	}
}
#endif // PlayerSettings_H
