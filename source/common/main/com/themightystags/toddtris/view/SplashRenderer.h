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

////////////////////////////////////////////////////////////////////////////////
// Superclass for simple renderers which are required simply to render the
// splash screen which is shown when the game starts.
////////////////////////////////////////////////////////////////////////////////
#ifndef SplashRenderer_H
#define SplashRenderer_H

#include "com/themightystags/toddtris/model/Well.h"
#include "com/themightystags/toddtris/view/WellRenderer.h"

using com::themightystags::toddtris::model::Well;

/**
 * Implementations should simply render a splash screen showing credits, etc
 */
namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				class SplashRenderer {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					SplashRenderer(const SplashRenderer& object);
					SplashRenderer& operator=(const SplashRenderer& object);

				public:
					SplashRenderer();
					virtual ~SplashRenderer();
					virtual void render(bool full) = 0;
				};
			}
		}
	}
}
#endif // SplashRenderer_H
