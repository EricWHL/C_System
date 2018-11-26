#ifndef GEN_FILE_H
#define GEN_FILE_H

typedef enum _GEN_FILE_OPE_RST {
    GEN_FILE_OPE_RST_OK,
    GEN_FILE_OPE_RST_ERR,
    GEN_FILE_OPE_RST_MAX
}GEN_FILE_OPE_RST;
    
GEN_FILE_OPE_RST Gen_FileWrite();
GEN_FILE_OPE_RST Gen_DirWrite();

#endif
