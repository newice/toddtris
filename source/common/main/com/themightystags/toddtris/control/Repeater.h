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

//
//  See description in WellController.h
//

#if !defined(com_themightystags_toddtris_control_RepeatHandler)
#define com_themightystags_toddtris_control_RepeatHandler

#include "com/themightystags/util/Timer.h"
#include "com/themightystags/toddtris/control/ActionHandler.h"
#include "com/themightystags/toddtris/model/Well.h"

using com::themightystags::util::Timer;
using com::themightystags::toddtris::control::ActionHandler;
using com::themightystags::toddtris::model::Well;

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace control {

				class Repeater {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					Repeater(const Repeater& object);
					Repeater& operator=(const Repeater& object);

				public:
					virtual ~Repeater();
					void start(ActionHandler &ah, Well &well);
					void carryOn(ActionHandler &ah, Well &well);
					void stop();

				protected:
					Repeater(long firstPauseMs, long repeatPauseMs);
					virtual void action(ActionHandler &ah, Well &well) = 0;

				private:
					Timer timer;
					long firstPauseMs;
					long repeatPauseMs;
					bool running;
				};

				class LeftRepeater: public Repeater {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					LeftRepeater(const LeftRepeater& object);
					LeftRepeater& operator=(const LeftRepeater& object);

				public:
					LeftRepeater(long firstPauseMs, long repeatPauseMs);
					virtual ~LeftRepeater();

				protected:
					void action(ActionHandler &ah, Well &well);
				};

				class RightRepeater: public Repeater {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					RightRepeater(const RightRepeater& object);
					RightRepeater& operator=(const RightRepeater& object);

				public:
					RightRepeater(long firstPauseMs, long repeatPauseMs);
					virtual ~RightRepeater();

				protected:
					void action(ActionHandler &ah, Well &well);
				};

				class DownRepeater: public Repeater {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					DownRepeater(const DownRepeater& object);
					DownRepeater& operator=(const DownRepeater& object);

				public:
					DownRepeater(long firstPauseMs, long repeatPauseMs);
					virtual ~DownRepeater();

				protected:
					void action(ActionHandler &ah, Well &well);
				};
			}
		}
	}
}
#endif // !defined(com_themightystags_toddtris_control_RepeatHandler)
