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

#include "com/themightystags/util/PathUtil.h" // class's header file

using com::themightystags::util::PathUtil;

string PathUtil::getDir(const string &path) {
	size_t found;
	found = path.find_last_of("/\\");
	return (found == string::npos) ? "" : path.substr(0,found+1);
}

char PathUtil::getSeparator(const string &path) {
	string dir = getDir(path);
	const char sep = (dir.length() > 0) ? dir.at(dir.length() - 1) : '/';
	return sep;
}
