#ifndef ANA_STRING_H
#define ANA_STRING_H

#include "com.h"

UBYTE* ANA_SubStr(UBYTE* p, UBYTE from, UBYTE to);

UBYTE ANA_CharAt(UBYTE* src, UINT index);

UINT ANA_Find(UBYTE* src, UBYTE c);
UINT ANA_FindFirstOf(UBYTE* src, UBYTE c);
UINT ANA_FindLastOf(UBYTE* src, UBYTE c);

#endif
