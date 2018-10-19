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
                    ANA_File_ResultInsert(ANA_FILE_OPE_RST_TYPE_FIND, filepath);
                    continue;
                }
            }
            
            continue;
        }
        
    }
    closedir(pathDir);

}

static ANA_FILE_OPE_RST ANA_File_ResultInsert(ANA_FILE_OPE_RST_TYPE type, UBYTE* result)
{
    UINT idx = 0;
    LOG("[%s:%d]IN \n", __FUNCTION__, __LINE__);
    
    if(NULL == s_stFileResult.buffer) {
        LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
        if(ANA_FILE_OPE_RST_TYPE_MAX == s_stFileResult.type) {
            LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
            switch (type) {
            case ANA_FILE_OPE_RST_TYPE_FIND:
            {
                LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
                UBYTE* tpData = (UBYTE*)malloc(strlen(ANA_FILE_RST_WORD_FIND));
                LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
                if(!tpData)
                    return ANA_FILE_OPE_RST_DATA_MLC_ERR;
                LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
                memcpy(tpData, ANA_FILE_RST_WORD_FIND,strlen(ANA_FILE_RST_WORD_FIND));
                s_stFileResult.buffer = tpData;
                LOG("[%s:%d]buffer:%s \n", __FUNCTION__, __LINE__ ,s_stFileResult.buffer[0]);
            }
            break;
            default:
                break;
            }
        }
    }

    if(NULL == result) {
        LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
        return  ANA_FILE_OPE_RST_NULL;
    }
    else {
        LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
        UBYTE* rstData = (UBYTE*)malloc(strlen(result));
        LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
        if(!rstData)
            return ANA_FILE_OPE_RST_DATA_MLC_ERR;
        LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
        memcpy(rstData, result, strlen(result));
        LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
        UBYTE** tmp = s_stFileResult.buffer;
        LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
        while(tmp){
            tmp ++;
        }
        LOG("[%s:%d] \n", __FUNCTION__, __LINE__);
        tmp = rstData;
        LOG("[%s:%d] tmp:%s \n", __FUNCTION__, __LINE__,tmp);
            
    }
    do {
        printf("[%s%d] !!!!!!!!buffer:%s\n", __FUNCTION__, __LINE__, s_stFileResult.buffer[idx]);        idx ++;
    }while(s_stFileResult.buffer[idx]);
    LOG("[%s:%d]OUT \n", __FUNCTION__, __LINE__);
}

void ANA_File_LastResult(UBYTE** result)
{
    result = s_stFileResult.buffer;
}
