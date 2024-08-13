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

/*
 * TwoPlayerStoppedState.h
 */

#ifndef TwoPlayerStoppedState_H_
#define TwoPlayerStoppedState_H_

#include "com/themightystags/toddtris/app/GameStoppedState.h"
#include "com/themightystags/toddtris/view/TwoPlayerRenderer.h"

using com::themightystags::toddtris::view::TwoPlayerRenderer;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {
				class TwoPlayerStoppedState: public GameStoppedState {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					TwoPlayerStoppedState(const TwoPlayerStoppedState& object);
					TwoPlayerStoppedState& operator=(const TwoPlayerStoppedState& object);

				public:
					TwoPlayerStoppedState(AppStateMachine &appStateMachine,
							const RendererFactory &rf,
							const vector<string> options,
							Well &w0, Well &w1, TwoPlayerGame &tpg,
							bool freezeOnEntry);
					virtual ~TwoPlayerStoppedState();

				protected:
					void draw(bool full,
							const vector<string> &options,
							int selectedIndex);

				private:
					TwoPlayerRenderer &renderer;
					Well &well0;
					Well &well1;
					TwoPlayerGame &tpg;
				};
			}
		}
	}
}

#endif /* TwoPlayerStoppedState_H_ */
