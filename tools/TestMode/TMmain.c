#include "TMmain.h"

void TM_Main()
{
    LOG("[%s:%d]IN \n", __FUNCTION__, __LINE__);
    ULONG a = 0xFFFFFFFF;
    LOG("%08x \n",a);
    LOG("%16d \n",a);
    LOG("[%s:%d]OUT \n", __FUNCTION__, __LINE__);
}
