#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#include "ANA_Format.h"

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

#define ANA_FORMAT_BUF_SIZE_1K (1024)

void ANA_FormatInit(char* filestream)
{
    LOG("[%s:%d]IN \n", __FUNCTION__, __LINE__);

    ASSERT(filestream);

    if(ANA_FILE_STS_EXIST == ANA_File_isExist(filestream)) {
        ANA_FormatLoad(filestream);
    }
    LOG("[%s:%d]OUT \n", __FUNCTION__, __LINE__);
}

void ANA_FormatLoad(char* filestream)
{
    SINT fd = -1;
    UBYTE buffer[ANA_FORMAT_BUF_SIZE_1K];
    SINT readsize = 0;
    
    ASSERT(filestream);
    memset(buffer, 0x00, ANA_FORMAT_BUF_SIZE_1K);
        
    LOG("[%s:%d]IN loadfile:%s \n", __FUNCTION__, __LINE__, filestream);

    fd = open (filestream, O_RDONLY);
    
    if(-1 != fd) {
        readsize = read(fd, buffer, ANA_FORMAT_BUF_SIZE_1K);
        LOG("read buffer size : %d \n",readsize);
        LOG("--------------------------------------------\n");
        LOG("read buffer:\n%s--------------------------------------------\n",buffer);

    }

    LOG("[%s:%d]OUT \n", __FUNCTION__, __LINE__);
    
}
