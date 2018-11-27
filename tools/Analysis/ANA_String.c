#include <string.h>
#include <stdlib.h>
#include "ANA_String.h"

UBYTE* ANA_SubString(UBYTE* src, UBYTE from, UBYTE to)
{
    ASSERT(src);
    UBYTE* dst;
    UBYTE* tmp = (UBYTE*)malloc(strlen(src));
    ASSERT(tmp);
    
    memset(tmp,0x00,strlen(src));
    LOG("[%s%d] IN\n",__FUNCTION__,__LINE__);
    while(*src != '\0') {
        if(from != *src) {
            if('\0'!= *tmp++) {
                *tmp = *src++;
            }
            if(to != *src) {
                continue;
            }
            else {
                break;
            }
        }
        else {
            if(to != *src) {
                *tmp = *src++;
                dst = tmp;
                continue;
            }
            else {
            }
        }
    }
    return dst;
    LOG("[%s%d] OUT\n",__FUNCTION__,__LINE__);
}
