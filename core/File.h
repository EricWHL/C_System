#ifndef _FILE_H
#define _FILE_H

#include "com.h"

typedef enum _FILE_OPE_ERR_STS {
    FILE_OPE_ERR_OK = 0,
    FILE_OPE_ERR_NG,
    FILE_OPE_ERR_MAX
}FILE_OPE_ERR_STS;

typedef enum _FILE_OPE_SEEK {
    FILE_OPE_SEEK_SET = 0,
    FILE_OPE_SEEK_CUR,
    FILE_OPE_SEEK_END,
    FILE_OPE_SEEK_MAX
}FILE_OPE_SEEK;

SINT File_Create(BYTE* filename);

BOOL File_IsExist(BYTE* filename);

FILE_OPE_ERR_STS File_Read(SINT fileid, POINTER buffer, UINT size);
FILE_OPE_ERR_STS File_Write(SINT fileid, POINTER buffer, UINT size);
void File_Seek(SINT fileid, UINT offset, FILE_OPE_SEEK whence);

FILE_OPE_ERR_STS File_Close(SINT fileid);
#endif
