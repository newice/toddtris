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

#include <string>

#ifndef BMGPlayer_H
#define BMGPlayer_H

/*
 * Dummy class which does nothing
 */
using namespace std;

namespace com {
	namespace themightystags {
		namespace toddtris{
			namespace sound {
				class BGMPlayer {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					BGMPlayer(const BGMPlayer& object);
					BGMPlayer& operator=(const BGMPlayer& object);

				public:
					// class constructor
					BGMPlayer(){}
					// class destructor
					~BGMPlayer(){}
					void process(){}
					//static void init(const string soundDir){}
					static void end(){}

				};
			}
		}
	}
}
#endif // BMGPlayer_H
