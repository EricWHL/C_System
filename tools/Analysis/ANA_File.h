#ifndef ANA_FILE_H
#define ANA_FILE_H

#include "com.h"

/*
  Analysis module enum defination.
*/

typedef enum _ANA_FILE_FIND_RST {
    ANA_FILE_FIND_RST_PATH_ERR = 0,
    ANA_FILE_FIND_RST_EXT_NAME_ERR,
    ANA_FILE_FIND_RST_NOT_FIND,
    ANA_FILE_FIND_RST_FIND,
    ANA_FILE_FIND_RST_MAX
}ANA_FILE_FIND_RST;

typedef enum _ANA_FILE_OPE_RST {
    ANA_FILE_OPE_RST_NULL = 0,
    ANA_FILE_OPE_RST_DATA_MLC_ERR,
    ANA_FILE_OPE_RST_TYPE_ERR,
    ANA_FILE_OPE_RST_REFRESHED,
    ANA_FILE_OPE_RST_MAX
}ANA_FILE_OPE_RST;

typedef enum _ANA_FILE_OPE_RST_STS {
    ANA_FILE_OPE_RST_STS_UPDATE = 0,
    ANA_FILE_OPE_RST_STS_FINISH,
    ANA_FILE_OPE_RST_STS_MAX
}ANA_FILE_OPE_RST_STS;

typedef enum _ANA_FILE_OPE_RST_TYPE {
    ANA_FILE_OPE_RST_TYPE_FIND = 0,
    ANA_FILE_OPE_RST_TYPE_MAX
}ANA_FILE_OPE_RST_TYPE;

typedef enum _ANA_FILE_STS {
    ANA_FILE_STS_EXIST = 0,
    ANA_FILE_STS_NOT_EXIST,
    ANA_FILE_STS_MAX
}ANA_FILE_STS;

/*
  Analysis module struct defination.
*/



/*
  Analysis module file operation function defination.
*/
void ANA_File_Init();

ANA_FILE_FIND_RST ANA_File_FindByExt(UBYTE* path, UBYTE* extname);
ANA_FILE_FIND_RST ANA_File_FindByName(UBYTE* path, UBYTE* filename);

ANA_FILE_STS ANA_File_isExist(UBYTE* path);

void ANA_File_LastResult(UBYTE** result);

#endif
