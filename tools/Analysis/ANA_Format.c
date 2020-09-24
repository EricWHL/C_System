#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#include "ANA_Format.h"
#include "ANA_String.h"
#include "ANA_Rule.h"

static ST_ANA_RULE_FORMAT *s_rule;

static void ANA_FormatAnaRule(UBYTE* format);

void ANA_FormatInit(UBYTE* fname)
{
    LOG("[%s:%d]IN \n", __FUNCTION__, __LINE__);

    ASSERT(fname);

    if(ANA_FILE_STS_EXIST == ANA_File_isExist(fname)) {
        ANA_FormatLoad(fname);
    }

    s_rule = NULL;
    
    LOG("[%s:%d]OUT \n", __FUNCTION__, __LINE__);
    LOG("[%s:%d]OUT-> %s \n", __FUNCTION__, __LINE__,ANA_TASK_NAME("aaaaa"));
}

void ANA_FormatLoad(UBYTE* filestream)
{
    SINT fd = -1;
    UBYTE buffer[ANA_FORMAT_BUF_SIZE_1K];
    SINT readsize = 0;
    UBYTE* tmp;
    UBYTE test;
    
    ASSERT(filestream);
    memset(buffer, 0x00, ANA_FORMAT_BUF_SIZE_1K);
        
    LOG("[%s:%d]IN loadfile:%s \n", __FUNCTION__, __LINE__, filestream);

    fd = open (filestream, O_RDONLY);
    
    if(-1 != fd) {

        readsize = read(fd, buffer, ANA_FORMAT_BUF_SIZE_1K);

        LOG("read buffer size : %d \n",readsize);
        LOG("--------------------------------------------\n");
        LOG("read buffer:\n%s--------------------------------------------\n",buffer);

        tmp = ANA_SubStr(buffer,ANA_WORD_DEF_WEL,ANA_WORD_DEF_RTN);

        LOG("--------------------------------------------\n");
        LOG("tmp:%s\n",tmp);

        ANA_FormatAnaRule(tmp);

        LOG("--------------------------------------------\n");
        
    }

    LOG("[%s:%d]OUT \n", __FUNCTION__, __LINE__);
    
}

static void ANA_FormatAnaRule(UBYTE* format)
{
    ASSERT(format);
    UBYTE* object = NULL;
    UBYTE* item = NULL;
    UBYTE itemindex = 0;
    LOG("[%s:%d]IN\n",__FUNCTION__,__LINE__);
    if(NULL == format) {
        return;
    }
    
    while('\0' != *format) {
        if(ANA_WORD_DEF_WEL == *format) {
            format++;
            continue;
        }
        if(ANA_WORD_DEF_MBKL == *format) {
            object = ANA_SubStr(format,ANA_WORD_DEF_MBKL,ANA_WORD_DEF_MBKR);
            LOG("[%s:%d]>>>>object:%s size:%d\n",__FUNCTION__,__LINE__,object,strlen(object));
            break;        
        }
    }

    object = ANA_ReplaceChar(object,ANA_WORD_DEF_MBKR, ANA_WORD_DEF_COM);
    object = ANA_ReplaceChar(object,ANA_WORD_DEF_MBKL, ANA_WORD_DEF_COM);

    LOG("[%s:%d]<<<<<object:%s size:%d\n",__FUNCTION__,__LINE__,object,strlen(object));

    while(itemindex < strlen(object) -1){
        LOG("[%s:%d]IN>>>itemindex:%d\n",__FUNCTION__,__LINE__,itemindex);

        item = ANA_SubStr(&object[itemindex +1], *(object + itemindex + 1), object[ANA_Find(&object[itemindex+1],ANA_WORD_DEF_COM)-1 + itemindex]);
        itemindex = ANA_Find(&object[itemindex+1],ANA_WORD_DEF_COM) + itemindex;
        
        LOG("[%s:%d]OUT<<<itemindex:%d\n",__FUNCTION__,__LINE__,itemindex);
    }

    LOG("[%s:%d]OUT\n",__FUNCTION__,__LINE__);
}

UBYTE** ANA_RuleAnalysis(UBYTE* object)
{
    ASSERT(object);

    UBYTE** result = NULL;
    UBYTE* item = NULL;
    UBYTE itemindex = 0;
    UBYTE* tmp = (UBYTE*)malloc(strlen(object));

    ASSERT(tmp);

    LOG("[%s:%d]IN\n",__FUNCTION__,__LINE__);

    memcpy(tmp,object,strlen(object));
    
    tmp = ANA_ReplaceChar(tmp, ANA_WORD_DEF_MBKR, ANA_WORD_DEF_COM);
    tmp = ANA_ReplaceChar(tmp, ANA_WORD_DEF_MBKL, ANA_WORD_DEF_COM);

    LOG("[%s:%d]<<<<<object:%s size:%d\n", __FUNCTION__, __LINE__, tmp, strlen(tmp));

    while(itemindex < strlen(tmp) -1){
        LOG("[%s:%d]IN>>>itemindex:%d\n",__FUNCTION__,__LINE__,itemindex);

        item = ANA_SubStr(&tmp[itemindex +1], *(tmp + itemindex + 1), tmp[ANA_Find(&tmp[itemindex+1],ANA_WORD_DEF_COM)-1 + itemindex]);
        itemindex = ANA_Find(&tmp[itemindex+1],ANA_WORD_DEF_COM) + itemindex;
        
        LOG("[%s:%d]OUT<<<itemindex:%d\n",__FUNCTION__,__LINE__,itemindex);
    }

    LOG("[%s:%d]OUT\n",__FUNCTION__,__LINE__);

    free(tmp);
        
}
