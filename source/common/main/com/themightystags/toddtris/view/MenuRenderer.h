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
// MenuRenderer is used to render menu screens with highlighting of selected
// options.
////////////////////////////////////////////////////////////////////////////////
#ifndef MenuRenderer_H
#define MenuRenderer_H

#include <string>
#include <vector>

using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				class MenuRenderer {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					MenuRenderer(const MenuRenderer& object);
					MenuRenderer& operator=(const MenuRenderer& object);

				public:
					MenuRenderer();
					virtual ~MenuRenderer();
					virtual void render(const vector<string> &options,
							const vector<bool> &selected, bool full) = 0;
				};
			}
		}
	}
}
#endif // MenuRenderer_H
