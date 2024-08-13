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

#ifndef TextRendererFactory_H
#define TextRendererFactory_H

#include "com/themightystags/toddtris/view/RendererFactory.h"

using com::themightystags::toddtris::view::RendererFactory;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				namespace text {
					class TextRendererFactory : public RendererFactory {

					private:
						TextRendererFactory();
						static const TextRendererFactory INSTANCE;


					public:
						virtual ~TextRendererFactory();
						SplashRenderer &getSplashRenderer() const;
						MenuRenderer &getMenuRenderer() const;
						OnePlayerRenderer &getOnePlayerRenderer() const;
						TwoPlayerRenderer &getTwoPlayerRenderer() const;
						void videoSync() const;
						void cleanup() const;

						static const TextRendererFactory &getInstance();
					};
				}
			}
		}
	}
}
#endif // TextRendererFactory_H
