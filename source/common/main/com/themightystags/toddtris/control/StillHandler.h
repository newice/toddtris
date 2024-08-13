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

///////////////////////////////////////////////////////////
//  StillHandler.h
//  Implementation of the Class StillHandler
//  Created on:      18-Nov-2008 19:33:47
//  Original author: ToddA
//
//  See description in WellController.h
//
///////////////////////////////////////////////////////////

#if !defined(EA_46CC585E_0E79_4dcb_A19F_8E4299906A76__INCLUDED_)
#define EA_46CC585E_0E79_4dcb_A19F_8E4299906A76__INCLUDED_

#include "com/themightystags/toddtris/model/Well.h"
#include "com/themightystags/toddtris/control/ActionHandler.h"

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace control {
				class StillHandler: public ActionHandler {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					StillHandler(const StillHandler& object);
					StillHandler& operator=(const StillHandler& object);

				public:
					virtual ~StillHandler();

					static StillHandler &getInstance();

					bool rotate(Well &well);
					bool antirotate(Well &well);
					bool left(Well &well);
					bool right(Well &well);
					bool down(Well &well);
					bool drop(Well &well);
					bool hold(Well &well);
					void restart(Well &well);
					void togglePause(Well &well);

				private:
					StillHandler();
					static StillHandler INSTANCE;

				};
			}
		}
	}
}
#endif // !defined(EA_46CC585E_0E79_4dcb_A19F_8E4299906A76__INCLUDED_)
