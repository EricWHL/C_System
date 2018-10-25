#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "com.h"

#include "ANA_IF.h"

#include "TMmain.h"

typedef enum  _PRO_CMD_INDEX {
    PRO_CMD_INDEX_0 = 0,
    PRO_CMD_INDEX_1,
    PRO_CMD_INDEX_2,
    PRO_CMD_INDEX_3,
    PRO_CMD_INDEX_4,
    PRO_CMD_INDEX_5,
    PRO_CMD_INDEX_6,
    PRO_CMD_INDEX_7,
    PRO_CMD_INDEX_8,
    PRO_CMD_INDEX_9,
    PRO_CMD_INDEX_10,
    PRO_CMD_INDEX_MAX
}PRO_CMD_INDEX;

void OS_HelpPro();
void OS_GenerateCodePro();
void OS_UTPro();
void OS_TestModePro();

void OS_ConfigPro(UBYTE* path, UBYTE* name);

void OS_ParamPro(int argv, char** argc);

int main (int argv, char** argc)
{

    LOG("[%s:%d]IN \n", __FUNCTION__, __LINE__);
    ANA_Init();
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
        param --;
        idx ++;
    } while(param);

    if((0 == strcmp("h",argc[PRO_CMD_INDEX_1]))
       ||(0 == strcmp("-h",argc[PRO_CMD_INDEX_1]))
       ||(0 == strcmp("-help",argc[PRO_CMD_INDEX_1]))
       ||(0 == strcmp("--help",argc[PRO_CMD_INDEX_1]))) {

        OS_HelpPro();
    }

    else if((0 == strcmp("c",argc[PRO_CMD_INDEX_1]))
            ||(0 == strcmp("-c",argc[PRO_CMD_INDEX_1]))
            ||(0 == strcmp("-config",argc[PRO_CMD_INDEX_1]))
            ||(0 == strcmp("--config",argc[PRO_CMD_INDEX_1]))) {

        OS_ConfigPro(argc[PRO_CMD_INDEX_2], argc[PRO_CMD_INDEX_3]);

    }

    else if((0 == strcmp("g",argc[PRO_CMD_INDEX_1]))
            ||(0 == strcmp("-g",argc[PRO_CMD_INDEX_1]))
            ||(0 == strcmp("-gen",argc[PRO_CMD_INDEX_1]))
            ||(0 == strcmp("--generate-code",argc[PRO_CMD_INDEX_1]))) {

    }

    else if((0 == strcmp("t",argc[PRO_CMD_INDEX_1]))
            ||(0 == strcmp("-t",argc[PRO_CMD_INDEX_1]))
            ||(0 == strcmp("-test",argc[PRO_CMD_INDEX_1]))
            ||(0 == strcmp("--testmode",argc[PRO_CMD_INDEX_1]))) {
        TM_Main();
    }

    else if((0 == strcmp("ut",argc[PRO_CMD_INDEX_1]))
            ||(0 == strcmp("-ut",argc[PRO_CMD_INDEX_1]))
            ||(0 == strcmp("-unittest",argc[PRO_CMD_INDEX_1]))) {

        OS_UTPro();
    }

    else if((0 == strcmp("r",argc[idx]))
            ||(0 == strcmp("-r",argc[idx]))
            ||(0 == strcmp("-run",argc[idx]))) {

        EventLoop_Create();

        EventLoop_Run();

        EventLoop_Exit();
    }

    else if((0 == strcmp("a",argc[idx]))
            ||(0 == strcmp("-a",argc[idx]))
            ||(0 == strcmp("-analy",argc[idx]))
            ||(0 == strcmp("--analysis-file",argc[idx]))) {

        OS_AnalysisPro(argc[PRO_CMD_INDEX_1]);
    }

    else {
            
    }

}

void OS_ConfigPro(UBYTE* path, UBYTE* name)
{
    LOG("[%s:%d]IN \n", __FUNCTION__, __LINE__);
    ASSERT(path);

    LOGI(path);

    ANA_File_FindByName(path , name);
    LOG("[%s:%d]OUT \n", __FUNCTION__, __LINE__);

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

