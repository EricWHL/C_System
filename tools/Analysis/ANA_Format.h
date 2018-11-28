#ifndef ANA_FORMAT_H
#define ANA_FORMAT_H

#include "ANA_File.h"

void ANA_FormatInit(UBYTE* filestream);

void ANA_FormatLoad(UBYTE* filestream);

UBYTE** ANA_GetRule();

#endif //ANA_FORMAT_H
