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

#ifndef GXRendererFactory_H
#define GXRendererFactory_H

#include "com/themightystags/toddtris/view/RendererFactory.h"

using com::themightystags::toddtris::view::RendererFactory;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				namespace gx {
					class GXRendererFactory : public RendererFactory {

					private:
						GXRendererFactory();
						static const GXRendererFactory INSTANCE;

						// the singleton instance of this class cannot be copied
						// and should be passed by reference
						GXRendererFactory(const GXRendererFactory& object);
						GXRendererFactory& operator=(const GXRendererFactory& object);


					public:
						virtual ~GXRendererFactory();
						SplashRenderer &getSplashRenderer() const;
						MenuRenderer &getMenuRenderer() const;
						OnePlayerRenderer &getOnePlayerRenderer() const;
						TwoPlayerRenderer &getTwoPlayerRenderer() const;
						void videoSync() const;
						void cleanup() const;
						void requestScreenshot() const;

						static const GXRendererFactory &getInstance();
					};
				}
			}
		}
	}
}
#endif // GXRendererFactory_H
