#ifndef _GENERATOR_H
#define _GENERATOR_H

#include "com.h"

typedef enum GEN_CODE_ERR {
    GEN_CODE_ERR_CFG_PATH_ERR,
    GEN_CODE_ERR_MAX
};

void Gen_Init( UBYTE* format);

void Gen_Code( UBYTE* cfgPath);
#endif
