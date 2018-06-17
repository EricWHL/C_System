#ifndef _COM_FUNC_H_
#define _COM_FUNC_H_

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

/*************************************
 *assert define
 ************************************/
#define ASSERT(exp)                                                     \
  do{                                                                   \
    if(!exp) {                                                          \
      printf("===========ASSERT===========\n");                         \
      printf("pointer is NULL! \n");                                    \
      printf("file is:%s function is:%s line is:%d\n",__FILE__,__func__,__LINE__); \
      printf("===========ASSERT===========\n");                         \
    }                                                                   \
  }while(0)

#endif
