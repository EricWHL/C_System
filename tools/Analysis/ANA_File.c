#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "ANA_File.h"

static UBYTE** s_lastRstBuffer = NULL;

/*
  inline function defination.
*/

static ANA_FILE_OPE_RST ANA_File_ResultInsert(UBYTE* result);




ANA_FILE_FIND_RST ANA_File_FindByExt(UBYTE* path, UBYTE* extname)
{
    DIR* pathDir = NULL;
    DIR* cfgDir = NULL;
    UBYTE filepath[256];
    UBYTE cfgpath[256];
    
    struct dirent* entry;
    struct stat buf;
    char* ext = NULL;

    memset(cfgpath, 0x00, sizeof(cfgpath));

    if(NULL == path) {
        printf("config file path is NULL!\n");
        return ;
    }
    
    if(NULL == extname) {
        printf("config external file name is NULL!\n");
        return ;
    }
    
    pathDir = opendir(path);

    if(NULL == pathDir) {
        printf("open dir failed!\n");
    }

    while(entry = readdir(pathDir)) {

        memset(filepath, 0x00, sizeof(filepath));
        strcat(filepath, path);

        if((0 == strcmp(".", entry->d_name))
           ||(0 == strcmp("..", entry->d_name))) {
            continue;
        }

        if('/' == filepath[strlen(filepath)-1]) {
            strcat(filepath, entry->d_name);
        }
        else {
            strcat(filepath, "/");
            strcat(filepath, entry->d_name);
        }

        stat(filepath, &buf);

        if(S_ISDIR(buf.st_mode)){

            cfgDir = opendir(filepath);

            if(NULL == cfgDir) {
                return ;
            }

            ANA_File_FindByExt(filepath, extname);
        }
        else {
            ext = strrchr(entry->d_name, '.');

            if(ext) {
                *ext = '\0';
                ext++;
            }

            if(NULL != ext) {
                if(0 == strcmp(ext, extname)) {
                    printf("file name is %s \n",filepath);
                    continue;
                }
            }
            
            continue;
        }
        
    }
    closedir(pathDir);

}

static ANA_FILE_OPE_RST ANA_File_ResultInsert(UBYTE* result)
{
    
    if(NULL == s_lastRstBuffer) {
        
    }
    else {
        if(NULL == result) {
            return  ANA_FILE_OPE_RST_NULL;
        }
        else {
            UBYTE* rstData = (UBYTE*)malloc(strlen(result));
            if(!rstData)
                return ANA_FILE_OPE_RST_DATA_MLC_ERR;
            
        }
    }

}

void ANA_File_LastResult(UBYTE** result)
{
    result = s_lastRstBuffer;
}
