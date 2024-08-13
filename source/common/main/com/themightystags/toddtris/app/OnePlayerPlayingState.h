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

#ifndef OnePlayerPlayingState_H
#define OnePlayerPlayingState_H

#include "com/themightystags/toddtris/app/PlayingState.h"
#include "com/themightystags/toddtris/view/OnePlayerRenderer.h"

using com::themightystags::toddtris::view::OnePlayerRenderer;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {

				class OnePlayerPlayingState: public PlayingState {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					OnePlayerPlayingState(const OnePlayerPlayingState& object);
					OnePlayerPlayingState& operator=(const OnePlayerPlayingState& object);

				public:
					OnePlayerPlayingState(AppStateMachine &appStateMachine,
							const RendererFactory &rf, Well &well);
					~OnePlayerPlayingState();

					void pausePressed(int controllerId);
					void ghostPressed(int controllerId);
					void draw(bool full);

				private:
					OnePlayerRenderer &renderer;
				};
			}
		}
	}
}
#endif // OnePlayerPlayingState_H
