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

///////////////////////////////////////////////////////////
//  Block.h
//  Implementation of the Class Block
//  Created on:      07-Nov-2008 19:17:57
//  Original author: ToddA
//
// The Block class represents one of the seven possible game pieces and
// includes methods to rotate the block.  A block is represented as a
// square composed of 2x2, 3x3 or 4x4 elements.  An element is either
// (a) 0 representing empty space
// or
// (b) a non-zero number representing part of the game piece.
// The 'size' of a block is found using the 'getSize' method and the value
// of a particular element is found using 'getElem'.
//
// In practice all four possible orientations of each of the seven different
// blocks are pre-calculated and the state of the Block instance is determined
// by 'blockNum' denoting which of the seven block types this block represents
// and 'rotationIndex' denoting its orientation.
// A 'reset' method is provided to return the block to its original orientation
// to assist in reusing Block instances.
//
///////////////////////////////////////////////////////////

#if !defined(EA_74C5F49A_458D_4261_A3E6_A78DD7EA2656__INCLUDED_)
#define EA_74C5F49A_458D_4261_A3E6_A78DD7EA2656__INCLUDED_

#include "com/themightystags/toddtris/model/KickOffset.h"

using com::themightystags::toddtris::model::KickOffset;

typedef int BaseElemsType[7][4][4];

namespace com {
	namespace themightystags {
		namespace toddtris {
			namespace model {
				class Block {

				// instances of this class cannot be copied
				// and should be passed by reference
				private:
					Block(const Block& object);
					Block& operator=(const Block& object);

				public:
					static const int NUM_BLOCKS = 7;
					static const int MAX_BLOCK_SIZE = 4;
					static const int X = 0;
					static const int O = 1;
					static const int T = 2;
					static const int L = 3;
					static const int J = 4;
					static const int I = 5;
					static const int S = 6;
					static const int Z = 7;

				private:
					static const int INITIALIZED;
					int blockNum;
					static const int NUM_ORIENTATIONS = 4;

				public:
					Block(int b);
					Block(int blockNum, int rotationIndex);
					virtual ~Block();
					int getSize() const;
					int getElem(int x, int y) const;
					void rotate();
					void antirotate();
					void reset();
					int getBlockNum() const;
					int getRotationIndex() const;
					int getNumKickOffsets() const;
					const KickOffset &getKickOffsetRotate(int kickIndex) const;
					const KickOffset &getKickOffsetAntirotate(int kickIndex) const;

				private:
					static const int
							BASE_ELEMS[NUM_BLOCKS][MAX_BLOCK_SIZE][MAX_BLOCK_SIZE];

					/**
					 * first index is the rotation index, second the block number, third and forth are the
					 * shape of the block
					 */
					static int
							ALL_ELEMS[NUM_ORIENTATIONS][NUM_BLOCKS][MAX_BLOCK_SIZE][MAX_BLOCK_SIZE];

					static const int BLOCK_SIZES[NUM_BLOCKS];

					/** The first index in the KickOffset arrays denotes the orientation we are rotating into, NOT the one we are coming from */
					static const int NUM_KICK_OFFSETS_I = 4;
					static const KickOffset *KICK_OFFSETS_I_ROTATE[NUM_ORIENTATIONS][NUM_KICK_OFFSETS_I];
					static const KickOffset *KICK_OFFSETS_I_ANTIROTATE[NUM_ORIENTATIONS][NUM_KICK_OFFSETS_I];
					static const int NUM_KICK_OFFSETS_OTHER = 4;
					static const KickOffset *KICK_OFFSETS_OTHER_ROTATE[NUM_ORIENTATIONS][NUM_KICK_OFFSETS_OTHER];
					static const KickOffset *KICK_OFFSETS_OTHER_ANTIROTATE[NUM_ORIENTATIONS][NUM_KICK_OFFSETS_OTHER];

					/* Should never be used */
					static const KickOffset DUMMY_KICK_OFFSET;

					int rotationIndex;

					static void copyElems(
							const int(&source)[MAX_BLOCK_SIZE][MAX_BLOCK_SIZE],
							int(&target)[MAX_BLOCK_SIZE][MAX_BLOCK_SIZE],
							int blockSize);

					static void rotateElems(
							const int(&source)[MAX_BLOCK_SIZE][MAX_BLOCK_SIZE],
							int(&target)[MAX_BLOCK_SIZE][MAX_BLOCK_SIZE],
							int blockSize);

					static int initAllElems();
				};
			}
		}
	}
}
#endif // !defined(EA_74C5F49A_458D_4261_A3E6_A78DD7EA2656__INCLUDED_)
