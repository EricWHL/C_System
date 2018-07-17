#include <stdio.h>

#include "com.h"

int main (int argv, char** argc)
{
    EventLoop_Create();
    EventLoop_Run();

    EventLoop_Exit();

    return 0;      

}
