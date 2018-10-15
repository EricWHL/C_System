#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "ConfigAnalysis.h"

void ConfigAna_Load(UBYTE* path)
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

            ConfigAna_Load(filepath);
        }
        else {
            ext = strrchr(entry->d_name, '.');

            if(ext) {
                *ext = '\0';
                ext++;
            }

            if(NULL != ext) {
                if(0 == strncmp(ext, "cfg", strlen("cfg"))) {
                    printf("find the config file!!!!\n");
                    printf("config file name is %s \n",filepath);

                    continue;
                }
            }
            
            continue;
        }
        
    }
    closedir(pathDir);

}
