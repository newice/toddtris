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
//  ActionHandler.h
//  Implementation of the Interface ActionHandler
//  Created on:      18-Nov-2008 18:12:02
//  Original author: ToddA
//
//  See description in WellController.h
//
///////////////////////////////////////////////////////////

#if !defined(EA_5DF6771D_FA98_4968_90DF_DE37F87DC195__INCLUDED_)
#define EA_5DF6771D_FA98_4968_90DF_DE37F87DC195__INCLUDED_

#include "com/themightystags/toddtris/model/Well.h"

using com::themightystags::toddtris::model::Well;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace control {
				class ActionHandler {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					ActionHandler(const ActionHandler& object);
					ActionHandler& operator=(const ActionHandler& object);

				public:
					ActionHandler() {}
					virtual ~ActionHandler() {}

					virtual bool rotate(Well &well) =0;
					virtual bool antirotate(Well &well) =0;
					virtual bool left(Well &well) =0;
					virtual bool right(Well &well) =0;
					virtual bool down(Well &well) =0;
					virtual bool drop(Well &well) =0;
					virtual bool hold(Well &well) =0;
					virtual void restart(Well &well) =0;
					virtual void togglePause(Well &well) =0;
				};
			}
		}
	}
}
#endif // !defined(EA_5DF6771D_FA98_4968_90DF_DE37F87DC195__INCLUDED_)
