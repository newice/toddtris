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

Wii notes
---------
- Tested against libogc v1.8.10.
- Requires grrlib to be installed, tested with version 4.3.2.
- It is also possible to compile a text based version of the game called textris using Makefile_wii_text.
- The supplied font, font1.ttf, is a copy of the file FreeMonoBold.ttf from the GRRLIB example "ttf".
  It is renamed here as it could be replaced with any other true type font.


MinGW notes
-----------
- The environment variable MINGW_HOME should be set to your MinGW install directory.
- There is no sound on the MinGW version.
MinGW version is text based.
MinGW version is mainly useful for developing without having to deploy to the Wii.  Most of the code is the
same except for rendering the screen and reading user input.