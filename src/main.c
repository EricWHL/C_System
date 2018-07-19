#include <stdio.h>
#include <string.h>
#include <stdlib.h>




#include "com.h"


void OS_Help();
void OS_ParamPro(int argv, char** argc);

int main (int argv, char** argc)
{
    
    OS_ParamPro(argv, argc);

    EventLoop_Create();
    EventLoop_Run();

    EventLoop_Exit();
    
    printf("[%s:%d]OUT \n", __FUNCTION__, __LINE__);
    return 0;      

}

void OS_ParamPro(int argv, char** argc)
{
    int param = argv;
    int idx = 0;
    
    do {
        printf("argv: %d argc :%s\n", idx, argc[idx]);
        if((0 == strcmp("h",argc[idx]))
            ||(0 == strcmp("-h",argc[idx]))
            ||(0 == strcmp("-help",argc[idx]))
            ||(0 == strcmp("--help",argc[idx]))) {
            OS_Help();
        }
        else {
            
        }

        param --;
        idx ++;
    } while(param);
}

void OS_Help()
{
    printf("*================================================================* \n");
    printf("*            This is a operation system for test                 * \n");
    printf("*================================================================* \n");
    printf("\n");
    printf("       *************          *************        *************   \n");
    printf("       *           *          *                          *         \n");
    printf("       *           *          *                          *         \n");
    printf("       *           *          *                          *         \n");
    printf("       *           *          *************              *         \n");
    printf("       *           *                      *              *         \n");
    printf("       *           *                      *              *         \n");
    printf("       *           *                      *              *         \n");
    printf("       *************          *************              *         \n");
    printf("\n");
    printf("*----------------------------------------------------------------* \n");
    printf("* 1.First you should make a config file to create module in os   * \n");
    printf("*----------------------------------------------------------------* \n");
    printf("\n");
}
