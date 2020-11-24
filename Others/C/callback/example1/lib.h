#ifndef _LIB_H_
#define _LIB_H_

typedef int (*libCallbackFunction_t)(char* str); //回调函数的格式 传入参数是char* 返回类型为int
int libPrintfFunction(char *str, libCallbackFunction_t callback);

#endif
