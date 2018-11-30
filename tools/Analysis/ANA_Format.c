#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#include "ANA_Format.h"
#include "ANA_String.h"
/*

  Analysis words defination.
  
 */

#define ANA_WORD_DEF_BBKL '{'
#define ANA_WORD_DEF_BBKR '}'

#define ANA_WORD_DEF_MBKL '['
#define ANA_WORD_DEF_MBKR ']'

#define ANA_WORD_DEF_SBKL '('
#define ANA_WORD_DEF_SBKR ')'

#define ANA_WORD_DEF_COM  ','
#define ANA_WORD_DEF_PER  '.'
#define ANA_WORD_DEF_SEM  ';'
#define ANA_WORD_DEF_COL  ':'
#define ANA_WORD_DEF_QUO  '"'

#define ANA_WORD_DEF_EXC  '!'
#define ANA_WORD_DEF_WEL  '#'
#define ANA_WORD_DEF_PEC  '%'
#define ANA_WORD_DEF_RTN  '\n'

#define ANA_FORMAT_BUF_SIZE_1K (1024)

static UBYTE** s_rule;

static void ANA_FormatAnaRule(UBYTE* format);

void ANA_FormatInit(UBYTE* filestream)
{
    LOG("[%s:%d]IN \n", __FUNCTION__, __LINE__);

    ASSERT(filestream);
    s_rule = NULL;

    if(ANA_FILE_STS_EXIST == ANA_File_isExist(filestream)) {
        ANA_FormatLoad(filestream);
    }
    LOG("[%s:%d]OUT \n", __FUNCTION__, __LINE__);
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

    while(itemindex < strlen(object)){
        LOG("[%s:%d]IN>>>itemindex:%d\n",__FUNCTION__,__LINE__,itemindex);

        item = ANA_SubStr(&object[itemindex],*(object + itemindex + 1),object[ANA_Find(&object[itemindex+1],ANA_WORD_DEF_COM)-1]);
        
        itemindex = ANA_Find(&object[itemindex+1],ANA_WORD_DEF_COM) + itemindex;
        
        LOG("[%s:%d]item:%s\n",__FUNCTION__,__LINE__,item);
        LOG("[%s:%d]OUT<<<itemindex:%d\n",__FUNCTION__,__LINE__,itemindex);
    }
    
    LOG("[%s:%d]OUT\n",__FUNCTION__,__LINE__);
}

