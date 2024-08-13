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

#ifndef MenuState_H
#define MenuState_H

#include "com/themightystags/toddtris/app/AppState.h"
#include "com/themightystags/toddtris/view/MenuRenderer.h"

using com::themightystags::toddtris::view::RendererFactory;
using com::themightystags::toddtris::view::MenuRenderer;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {

				class MenuState : public AppState {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					MenuState(const MenuState& object);
					MenuState& operator=(const MenuState& object);

				public:
					MenuState(AppStateMachine &appStateMachine, const RendererFactory &rf);
					~MenuState();

				protected:
					MenuRenderer &menuRenderer;
				};
			}
		}
	}
}
#endif // MenuState_H
