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
    ANA_FILE_OPE_RST_MAX
}ANA_FILE_OPE_RST;


/*
  Analysis module struct defination.
*/



/*
  Analysis module file operation function defination.
*/
ANA_FILE_FIND_RST ANA_File_FindByExt(UBYTE* path, UBYTE* extname);

void ANA_File_LastResult(UBYTE** result);

#endif
