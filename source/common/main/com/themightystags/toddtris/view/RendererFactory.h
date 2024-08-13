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
//
// See RendererFactory.h for description
//
////////////////////////////////////////////////////////////////////////////////
#ifndef RendererFactory_H
#define RendererFactory_H

#include "com/themightystags/toddtris/view/SplashRenderer.h"
#include "com/themightystags/toddtris/view/MenuRenderer.h"
#include "com/themightystags/toddtris/view/OnePlayerRenderer.h"
#include "com/themightystags/toddtris/view/TwoPlayerRenderer.h"

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace view {
				class RendererFactory {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					RendererFactory(const RendererFactory& object);
					RendererFactory& operator=(const RendererFactory& object);

				public:
					RendererFactory();
					virtual ~RendererFactory();
					virtual SplashRenderer &getSplashRenderer() const = 0;
					virtual MenuRenderer &getMenuRenderer() const = 0;
					virtual OnePlayerRenderer &getOnePlayerRenderer() const = 0;
					virtual TwoPlayerRenderer &getTwoPlayerRenderer() const = 0;
					virtual void videoSync() const = 0;
					virtual void cleanup() const = 0;
					virtual void requestScreenshot() const;
				};
			}
		}
	}
}
#endif // RendererFactory_H
