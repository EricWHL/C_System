#include <pthread.h>

#include "Timer.h"
static void* Timer_Exe(void* data)
{
    printf("[%d][%s:%d]\n",clock(),__FUNCTION__,__LINE__);    
    printf("[%d][%s:%d]\n",clock(),__FUNCTION__,__LINE__);    

}

void Timer_Create()
{
    pthread_t id;
    SINT ret = pthread_create(&id, NULL, Timer_Exe, 0);
    if(0 != ret) {
        printf("pthread_create is Error!!!!!!!!!!!!!!!!!!!!!\n");
    }
    pthread_join(id,0);

}

void Timer_Run()
{
    
}
