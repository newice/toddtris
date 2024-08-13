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

#ifndef TwoPlayerPausedState_H_
#define TwoPlayerPausedState_H_

#include "com/themightystags/toddtris/app/TwoPlayerStoppedState.h"

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {

				class TwoPlayerPausedState: public TwoPlayerStoppedState {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					TwoPlayerPausedState(const TwoPlayerPausedState& object);
					TwoPlayerPausedState& operator=(const TwoPlayerPausedState& object);

				public:
					TwoPlayerPausedState(AppStateMachine &appStateMachine,
							const RendererFactory &rf,
							Well &w0, Well &w1, TwoPlayerGame &tpg);
					virtual ~TwoPlayerPausedState();

				protected:
					void optionSelected(string option);

				private:
					static const string RESUME;
					static const string QUIT;
					static const vector<string> getOptions();
				};
			}
		}

	}

}

#endif /* TwoPlayerPausedState_H_ */
