#include <stdio.h>

#include "common_def.h"
#include "common_func.h"
static void obj_callback (void* param);

static void obj_callback (void* param)
{
	printf("obj_callback!\n");
}
int main (char* argv,char*argc)
{
	st_object st_obj;
	char *cp_point = NULL;
	st_obj.type = FUNC_TYPE_CALLBACK;
	st_obj.function = obj_callback;
	st_obj.function ("aa");
	printf("hello!\n");
	ASSERT(cp_point);

}
