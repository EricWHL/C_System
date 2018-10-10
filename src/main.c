#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "com.h"


void OS_HelpPro();
void OS_ConfigPro(UBYTE* path);
void OS_GenerateCodePro();
void OS_UTPro();
void OS_TestModePro();
void OS_ParamPro(int argv, char** argc);

int main (int argv, char** argc)
{

    LOG("[%s:%d]IN \n", __FUNCTION__, __LINE__);

    OS_ParamPro(argv, argc);

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
            OS_HelpPro();
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
            ||(0 == strcmp("--generate-code",argc[idx]))) {
            OS_ConfigPro(argc[idx + 1]);
        }
        else if((0 == strcmp("a",argc[idx]))
                ||(0 == strcmp("-a",argc[idx]))
                ||(0 == strcmp("-analy",argc[idx]))
                ||(0 == strcmp("--analysis-file",argc[idx]))) {
            OS_AnalysisPro(argc[idx + 1]);
        }
        else if((0 == strcmp("t",argc[idx]))
                ||(0 == strcmp("-t",argc[idx]))
                ||(0 == strcmp("-test",argc[idx]))
                ||(0 == strcmp("--testmode",argc[idx]))) {
            OS_TestModePro();
        }
        else if((0 == strcmp("r",argc[idx]))
                ||(0 == strcmp("-r",argc[idx]))
                ||(0 == strcmp("-run",argc[idx]))) {

            EventLoop_Create();
            EventLoop_Run();

            EventLoop_Exit();
        }

        else {
            
        }

        param --;
        idx ++;
    } while(param);
}

void OS_ConfigPro(UBYTE* path)
{
    ASSERT(path);

    LOGI(path);

    ConfigAna_Load( path );
}

void OS_AnalysisPro(UBYTE* path)
{
    
}

void OS_TestModePro()
{
    
}

void OS_GenerateCodePro()
{
    
}

void OS_UTPro()
{
    
}

void OS_HelpPro()
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

