#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "ANA_File.h"


/*
  inline defination.
*/
#define ANA_FILE_RST_WORD_FIND "find result:"

/*
  inline enum defination.
*/

/*
  inline structure defination.
*/

typedef struct _ST_ANA_FILE_OPE_RST {
    ANA_FILE_OPE_RST result;
    ANA_FILE_OPE_RST_STS status;
    ANA_FILE_OPE_RST_TYPE type;
    UBYTE** buffer;
}ST_ANA_FILE_OPE_RST;

/*
  inline variable defination.
*/

static ST_ANA_FILE_OPE_RST s_stFileResult;

/*
  inline function defination.
*/

static ANA_FILE_OPE_RST ANA_File_ResultInsert(ANA_FILE_OPE_RST_TYPE type, UBYTE* result);

void ANA_File_Init()
{
    LOG("[%s:%d]IN \n", __FUNCTION__, __LINE__);
    s_stFileResult.result = ANA_FILE_OPE_RST_MAX;
    s_stFileResult.status = ANA_FILE_OPE_RST_STS_MAX;
    s_stFileResult.type = ANA_FILE_OPE_RST_TYPE_MAX;
    s_stFileResult.buffer = NULL;
    LOG("[%s:%d]OUT \n", __FUNCTION__, __LINE__);
}

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
        LOG("config file path is NULL!\n");
        return ;
    }
    
    if(NULL == extname) {
        LOG("config external file name is NULL!\n");
        return ;
    }
    
    pathDir = opendir(path);

    if(NULL == pathDir) {
        LOG("open dir failed!\n");
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
                    LOG("file name is =>%s \n",filepath);
                    ANA_File_ResultInsert(ANA_FILE_OPE_RST_TYPE_FIND, filepath);
                    continue;
                }
            }
            
            continue;
        }
        
    }
    closedir(pathDir);

}

ANA_FILE_FIND_RST ANA_File_FindByName(UBYTE* path, UBYTE* filename)
{
    DIR* pathDir = NULL;
    DIR* cfgDir = NULL;
    UBYTE filepath[256];
    UBYTE cfgpath[256];
    
    struct dirent* entry;
    struct stat buf;
    char* ext = NULL;
    LOG("[%s:%d]IN \n", __FUNCTION__, __LINE__);
    memset(cfgpath, 0x00, sizeof(cfgpath));

    if(NULL == path) {
        LOG("config file path is NULL!\n");
        return ;
    }
    
    if(NULL == filename) {
        LOG("config external file name is NULL!\n");
        return ;
    }
    
    pathDir = opendir(path);

    if(NULL == pathDir) {
        LOG("open dir failed!\n");
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

            ANA_File_FindByName(filepath, filename);
        }
        else {
            if(0 == strncmp(entry->d_name, filename,strlen(filename))) {
                LOG("file name is =>%s \n",filepath);
                ANA_File_ResultInsert(ANA_FILE_OPE_RST_TYPE_FIND, filepath);
                continue;
            }
        }
        continue;
    }
    LOG("[%s:%d]OUT \n", __FUNCTION__, __LINE__);
    closedir(pathDir);
}

static ANA_FILE_OPE_RST ANA_File_ResultInsert(ANA_FILE_OPE_RST_TYPE type, UBYTE* result)
{
    static UINT idx = 0;
    LOG("[%s:%d]IN idx :%d\n", __FUNCTION__, __LINE__,idx);
    if(NULL == s_stFileResult.buffer) {
        if(ANA_FILE_OPE_RST_TYPE_MAX == s_stFileResult.type) {
            switch (type) {
            case ANA_FILE_OPE_RST_TYPE_FIND:
            {
                s_stFileResult.buffer = (UBYTE*)malloc(strlen(ANA_FILE_RST_WORD_FIND));
                if(!s_stFileResult.buffer) {
                    return  ANA_FILE_OPE_RST_NULL;
                }
                strncpy(s_stFileResult.buffer, ANA_FILE_RST_WORD_FIND, strlen(ANA_FILE_RST_WORD_FIND));
                
                idx ++;

                s_stFileResult.type = ANA_FILE_OPE_RST_TYPE_FIND;
            }
            break;
            default:
                break;
            }
        }
    }
    LOG("[%s:%d]-> idx :%d\n", __FUNCTION__, __LINE__,idx);
    if(NULL == result) {
        return  ANA_FILE_OPE_RST_NULL;
    }
    else {
        s_stFileResult.buffer[idx] = (UBYTE*)malloc(strlen(result));

        if(!s_stFileResult.buffer[idx])
            return ANA_FILE_OPE_RST_DATA_MLC_ERR;
        strncpy(s_stFileResult.buffer[idx],result,strlen(result));
        idx ++;
    }
    LOG("[%s:%d]OUT idx:%d \n", __FUNCTION__, __LINE__,idx);
}

void ANA_File_LastResult(UBYTE** result)
{
    result = s_stFileResult.buffer;
}
