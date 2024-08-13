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

#ifndef SplashState_H
#define SplashState_H

#include "com/themightystags/toddtris/app/AppState.h"
#include "com/themightystags/toddtris/view/SplashRenderer.h"

using com::themightystags::toddtris::view::SplashRenderer;

using namespace std;

/**
 * This is a simple state where we simply show the splash screen showing credits, etc
 */
namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {

				class SplashState: public AppState {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					SplashState(const SplashState& object);
					SplashState& operator=(const SplashState& object);

				public:
					SplashState(AppStateMachine &appStateMachine,
							const RendererFactory &rf);

					~SplashState();

					void draw(bool full);
					void onePressed(int controllerId);
					void twoPressed(int controllerId);
					void pausePressed(int controllerId);
					void ghostPressed(int controllerId);
					void holdPressed(int controllerId);
					void dropPressed(int controllerId);

				private:
					SplashRenderer &renderer;
				};
			}
		}
	}
}
#endif // SplashState_H
