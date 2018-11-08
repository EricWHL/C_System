#include "RuntimeIF.h"

void OS_Init()
{
    ModuleMgr_init();
    EventLoop_Create();
}

void OS_Run()
{
    EventLoop_Run();
}

void OS_Exit()
{
    EventLoop_Exit();
}
