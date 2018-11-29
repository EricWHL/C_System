#include <string.h>
#include <stdlib.h>

#include "ANA_String.h"

UBYTE* ANA_SubStr(UBYTE* p, UBYTE from, UBYTE to)
{
    ASSERT(p);
    UBYTE* dst;
    UBYTE* src = p;    
    UBYTE* tmp = (UBYTE*)malloc(strlen(src));
    ASSERT(tmp);
    
    memset(tmp,0x00,strlen(src));

    LOG("[%s:%d] IN\n",__FUNCTION__,__LINE__);
    LOG("[%s:%d] src:%s\n",__FUNCTION__,__LINE__,src);
    LOG("[%s:%d] from:%c\n",__FUNCTION__,__LINE__,from);
    LOG("[%s:%d] to:%c\n",__FUNCTION__,__LINE__,to);
    while(*src != '\0') {
        if(from != *src) {
            if('\0'!= *tmp++) {
                *tmp = *src;
            }
            if(to != *src) {
                src++;
                continue;
            }
            else {
                *tmp = *src;
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
    LOG("[%s:%d] dst:%s\n",__FUNCTION__,__LINE__,dst);
    LOG("[%s:%d] OUT\n",__FUNCTION__,__LINE__);
    return dst;

}

UBYTE ANA_CharAt(UBYTE* src, UINT index)
{
    ASSERT(src);

    LOG("[%s:%d]\nsrc:%s index:%d result:%c\n",__FUNCTION__,__LINE__,src, index, *(src+index));

    return  *(src + index);
}

UINT ANA_Find(UBYTE* src, UBYTE c)
{
    ASSERT(src);

    UBYTE* p = src;
    while(c != *src++);
    LOG("[%s:%d]IN src:%s c:%c\n",__FUNCTION__,__LINE__,src,c);
    LOG("[%s:%d]OUT rst:%d\n",__FUNCTION__,__LINE__,(src-p));
    return (src-p);
}

UINT ANA_FindFirstOf(UBYTE* src, UBYTE c)
{
    return ANA_Find(src, c);
}

UINT ANA_FindLastOf(UBYTE* src, UBYTE c)
{
    ASSERT(src);
    
    UBYTE* p = src + strlen(src);

    while(c != *p--);

    return (p - src +1);
}

UBYTE* ANA_EraseIndex(UBYTE* src, UINT index)
{
    ASSERT(src);
    UBYTE* p = (UBYTE*)malloc(strlen(src));
    UBYTE* it = src;
    UBYTE* result = p;
    ASSERT(p);
    memset(p, 0x00, strlen(src));

    while('\0'!= *src){
        if(index != (src - it)) {
            *p = *src++;
            p++;
            continue;
        }
        else {
            src++;
            *p = *src++;
            p++;
            continue;
        }
        
    }

    LOG("[%s:%d]OUT result:%s\n",__FUNCTION__,__LINE__,result);
    return result;
}

UBYTE* ANA_ReplaceIndex(UBYTE* src, UINT index,UBYTE c)
{
    ASSERT(src);

    *(src + index) = c;
    LOG("[%s:%d]OUT result:%s\n",__FUNCTION__,__LINE__,src);
    return src;
    
}

UBYTE* ANA_ReplaceChar(UBYTE* src, UBYTE from, UBYTE to)
{
    UBYTE* rst = NULL;
    
    LOG("[%s:%d]IN src:%s from:%c to:%c\n",__FUNCTION__,__LINE__,src, from, to);
    
    ASSERT(src);
    rst = src;
    while('\0' != *src) {
        if(from == *src) {
            *src = to;
        }
        src++;
    }

    LOG("[%s:%d]OUT resule:%s\n",__FUNCTION__,__LINE__,rst);
    return rst;
}
