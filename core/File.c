#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "File.h"

SINT File_Create(BYTE* filename)
{
    SINT fd = 0;
    
    if(NULL == filename) {
        return -1;
    }

    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR , S_IRWXU | S_IRWXG | S_IRWXO);

    return fd;
}

BOOL File_IsExist(BYTE* filename)
{
    SINT fd = -1;
    BOOL ret = FALSE;
    
    if(NULL == filename) {
        return FALSE;
    }

    fd = open(filename, O_RDONLY);
    
    if(-1 != fd) {
        ret = TRUE;
    }
    else {
        ret = FALSE;
    }
    
    close(fd);

    return ret;
}

FILE_OPE_ERR_STS File_Read(SINT fileid, POINTER buffer, UINT size)
{
    SINT ret;
    if(-1 == fileid) {
        return FILE_OPE_ERR_NG;
    }

    if (NULL == buffer) {
        return FILE_OPE_ERR_NG;
    }
    
    else {
        ret = read(fileid, buffer, size);
        if(-1 == ret) {
            return FILE_OPE_ERR_NG;
        }
        else {
            return FILE_OPE_ERR_OK;
        }
    }
}

FILE_OPE_ERR_STS File_Write(SINT fileid, POINTER buffer, UINT size)
{
    SINT ret;
    if(-1 == fileid) {
        return FILE_OPE_ERR_NG;
    }

    if (NULL == buffer) {
        return FILE_OPE_ERR_NG;
    }
    
    else {
        ret = write(fileid, buffer, size);
        if(-1 == ret) {
            return FILE_OPE_ERR_NG;
        }
        else {
            return FILE_OPE_ERR_OK;
        }
    }
}

void File_Seek(SINT fileid, UINT offset, FILE_OPE_SEEK whence)
{
    SINT ret;
    
    if(-1 == fileid) {
        return FILE_OPE_ERR_NG;
    }

    switch(whence) {
    case FILE_OPE_SEEK_SET:
        lseek(fileid, offset, SEEK_SET);
        break;
    case FILE_OPE_SEEK_CUR:
        lseek(fileid, offset, SEEK_CUR);
        break;
    case FILE_OPE_SEEK_END:
        lseek(fileid, offset, SEEK_END);
        break;
    default:
        break;
    }
}

FILE_OPE_ERR_STS File_Close(SINT fileid)
{
    if(-1 == fileid) {
        return FILE_OPE_ERR_NG;
    }
    else {
        close(fileid);
        return FILE_OPE_ERR_OK;
    }
}
