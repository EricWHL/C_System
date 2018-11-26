#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "Generator.h"

#define GEN_KW_SIZE (32)
#define GEN_KW_BUF_SIZE (32)

static UBYTE s_keyword[GEN_KW_SIZE][GEN_KW_BUF_SIZE];

void Gen_Init(UBYTE* format)
{
    memset(s_keyword, 0x00, sizeof(s_keyword));
    
}

void Gen_Code( UBYTE* cfgPath)
{
    
}
