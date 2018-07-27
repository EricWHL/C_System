#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "com.h"


void OS_Help();
void OS_ConfigPro(UBYTE* path);
void OS_GenerateCodePro();
void OS_ParamPro(int argv, char** argc);

int main (int argv, char** argc)
{

    LOG("[%s:%d]IN \n", __FUNCTION__, __LINE__);

    OS_ParamPro(argv, argc);

    EventLoop_Create();
    EventLoop_Run();

    EventLoop_Exit();
    
    LOG("[%s:%d]OUT \n", __FUNCTION__, __LINE__);
    return 0;      

}

void OS_ParamPro(int argv, char** argc)
{
    int param = argv;
    int idx = 0;
    
    do {
        LOG("argv: %d argc :%s\n", idx, argc[idx]);
        if((0 == strcmp("h",argc[idx]))
            ||(0 == strcmp("-h",argc[idx]))
            ||(0 == strcmp("-help",argc[idx]))
            ||(0 == strcmp("--help",argc[idx]))) {
            OS_Help();
        }
        else if((0 == strcmp("c",argc[idx]))
            ||(0 == strcmp("-c",argc[idx]))
            ||(0 == strcmp("-config",argc[idx]))
            ||(0 == strcmp("--config",argc[idx]))) {
            OS_ConfigPro(argc[idx + 1]);
        }
        else if((0 == strcmp("g",argc[idx]))
            ||(0 == strcmp("-g",argc[idx]))
            ||(0 == strcmp("-gen",argc[idx]))
            ||(0 == strcmp("--generate",argc[idx]))) {
            OS_ConfigPro(argc[idx + 1]);
        }
        else {
            
        }

        param --;
        idx ++;
    } while(param);
}

void OS_ConfigPro(UBYTE* path)
{
    ConfigAna_Load( path );
}

void OS_GenerateCodePro()
{
    
}

void OS_Help()
{
    LOG("*================================================================* \n");
    LOG("*            This is a operation system for test                 * \n");
    LOG("*================================================================* \n");
    LOG("\n");
    LOG("       *************          *************        *************   \n");
    LOG("       *           *          *                          *         \n");
    LOG("       *           *          *                          *         \n");
    LOG("       *           *          *                          *         \n");
    LOG("       *           *          *************              *         \n");
    LOG("       *           *                      *              *         \n");
    LOG("       *           *                      *              *         \n");
    LOG("       *           *                      *              *         \n");
    LOG("       *************          *************              *         \n");
    LOG("\n");
    LOG("*----------------------------------------------------------------* \n");
    LOG("* 1.First you should make a config file to create module in os   * \n");
    LOG("*----------------------------------------------------------------* \n");
    LOG("\n");
}

