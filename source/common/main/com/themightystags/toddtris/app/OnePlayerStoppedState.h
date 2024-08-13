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
 * OnePlayerStoppedState.h
 *
 *  Created on: 10-Feb-2009
 *      Author: todda
 */

#ifndef ONEPLAYERSTOPPEDSTATE_H_
#define ONEPLAYERSTOPPEDSTATE_H_

#include "com/themightystags/toddtris/app/GameStoppedState.h"
#include "com/themightystags/toddtris/view/OnePlayerRenderer.h"

using com::themightystags::toddtris::view::OnePlayerRenderer;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {
				class OnePlayerStoppedState: public GameStoppedState {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					OnePlayerStoppedState(const OnePlayerStoppedState& object);
					OnePlayerStoppedState& operator=(const OnePlayerStoppedState& object);

				public:
					OnePlayerStoppedState(AppStateMachine &appStateMachine,
							const RendererFactory &rf,
							const vector<string> options,
							Well &well, bool freezeOnEntry);
					virtual ~OnePlayerStoppedState();

				protected:
					void draw(bool full,
							const vector<string> &options,
							int selectedIndex);

				private:
					OnePlayerRenderer &renderer;
					Well &well;
				};
			}
		}
	}
}

#endif /* ONEPLAYERSTOPPEDSTATE_H_ */
