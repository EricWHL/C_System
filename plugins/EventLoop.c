#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "EventLoop.h"

static EventLoop* loop = NULL;

EventLoop* EventLoop_Create()
{
    if(NULL == loop) {
        loop = (EventLoop*)malloc(sizeof(EventLoop));
        if(NULL == loop) {
            return NULL;
        }
    
        loop->event = NULL;
    }
    else {
        return loop;
    }
    
    return loop;
}

void EventLoop_Destory()
{
    
}

EventLoop* EventLoop_Inst()
{
    if(NULL == loop) {
        return EventLoop_Create();
    }
    return loop;
}

BOOL EventLoop_IsEmpty()
{
    
}

EL_OPE_RST EventLoop_Run()
{
    
}

EL_OPE_RST EventLoop_Exit()
{
    
}

EL_OPE_RST EventLoop_SendEvent(Event* event)
{
    
}
