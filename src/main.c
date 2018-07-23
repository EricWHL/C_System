#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include "com.h"


void OS_Help();
void OS_ConfigPro(UBYTE* path);
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
        else if((0 == strcmp("c",argc[idx]))
            ||(0 == strcmp("-c",argc[idx]))
            ||(0 == strcmp("-config",argc[idx]))
            ||(0 == strcmp("--config",argc[idx]))) {
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
    DIR* pathDir = NULL;
    DIR* cfgDir = NULL;
    UBYTE filepath[256];
    UBYTE cfgpath[256];
    
    struct dirent* entry;
    struct stat buf;

    memset(cfgpath, 0x00, sizeof(cfgpath));

    if(NULL == path) {
        printf("config file path is NULL!\n");
    }
    
    pathDir = opendir(path);

    if(NULL == pathDir) {
        printf("open dir failed!\n");
    }
    
    while(entry = readdir(pathDir)) {

        memset(filepath, 0x00, sizeof(filepath));
        strcat(filepath, path);

        if('/' == filepath[strlen(filepath)]) {
            strcat(filepath, entry->d_name);
        }
        else {
            strcat(filepath, "/");
            strcat(filepath, entry->d_name);
        }
        
        stat(filepath, &buf);

        printf("name:%s ",entry->d_name);

        if(S_ISDIR(buf.st_mode)){
            printf("is a dir\n");
        }
        else {
            printf("is a file\n");
        }
        
    }
    closedir(pathDir);
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
