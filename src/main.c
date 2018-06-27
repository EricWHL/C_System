#include <stdio.h>

#include "com.h"
#include "EventLoop.h"
#include "Timer.h"
int main (int argv, char** argc)
{

    EventLoop_Create();
    Timer_Create();
    EventLoop_Run();

    EventLoop_Exit();

    return 0;      

}
