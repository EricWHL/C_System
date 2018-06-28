#include <pthread.h>
#include "EventLoop.h"
#include "Timer.h"
static void* Timer_Exe(void* data)
{
    printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
    while(1) {
        printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
        sleep(1);
        EventLoop_Wakeup();
        printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
    }
}

void Timer_Create()
{
    pthread_t id;
    printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
    SINT ret = pthread_create(&id, NULL, Timer_Exe, 0);
    if(0 != ret) {
        printf("pthread_create is Error!!!!!!!!!!!!!!!!!!!!!\n");
    }

    printf("[%s:%d]\n",__FUNCTION__,__LINE__);    
    pthread_join(id,0);

}

void Timer_Run()
{
    
}
