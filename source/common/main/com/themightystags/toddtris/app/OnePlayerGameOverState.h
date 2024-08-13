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

/*
 * OnePlayerGameOverState.h
 */

#ifndef OnePlayerGameOverState_H_
#define OnePlayerGameOverState_H_

#include "com/themightystags/toddtris/app/OnePlayerStoppedState.h"

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace app {

				class OnePlayerGameOverState: public OnePlayerStoppedState {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					OnePlayerGameOverState(const OnePlayerGameOverState& object);
					OnePlayerGameOverState& operator=(const OnePlayerGameOverState& object);

				public:
					OnePlayerGameOverState(AppStateMachine &appStateMachine,
							const RendererFactory &rf,
							Well &well);
					virtual ~OnePlayerGameOverState();

				protected:
					void optionSelected(string option);

				private:
					static const string RESTART;
					static const string QUIT;
					static const vector<string> getOptions();
				};
			}
		}

	}

}

#endif /* OnePlayerGameOverState_H_ */
