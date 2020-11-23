#include <stdio.h>
#include "lib.h"

int libPrintfFunction(char *str, libCallbackFunction_t callback)
{
//假设我是lib开发者（系统编程）,在提供接口时，想给应用开发者(应用编程)执行它想要执行自定操作操作 提高灵活性
  	printf("[%s]This is lib function,printf main str: %s\n",__func__,str);
  	char* libstr = "this is lib str";
  	callback(libstr);
  	return 0;
}
