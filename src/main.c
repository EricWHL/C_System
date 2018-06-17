#include <stdio.h>

#include "com.h"

static void obj_callback (void* param);

static void obj_callback (void* param)
{
	printf("obj_callback!\n");
    printf("param %p!\n",param);
}

int main (int argv, char** argc)
{
    st_object st_obj;
    char *cp_point = NULL;
    BYTE a = 1;
    st_obj.type = FUNC_TYPE_CALLBACK;
    st_obj.function = obj_callback;
    st_obj.function ("aa");
    printf("hello!\n");
    ASSERT(cp_point);
    printf("a's value:%d\n",a);
    return 0;      
}
