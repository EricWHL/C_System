#ifndef ANA_FORMAT_H
#define ANA_FORMAT_H

#include "ANA_File.h"

typedef struct _ST_ANA_RULE_FORMAT{
    UBYTE itemcount;
    UBYTE** item;
}ST_ANA_RULE_FORMAT;

void ANA_FormatInit(UBYTE* filestream);

void ANA_FormatLoad(UBYTE* filestream);

UBYTE** ANA_RuleAnalysis(UBYTE* object);

#endif //ANA_FORMAT_H
