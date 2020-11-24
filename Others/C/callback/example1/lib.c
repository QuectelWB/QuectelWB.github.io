#include <stdio.h>
#include "lib.h"

int libPrintfFunction(char *str, libCallbackFunction_t callback)
{
  	printf("[%s]This is lib function,printf main str: %s\n",__func__,str);
  	char* libstr = "this is lib str";
  	callback(libstr);
  	return 0;
}
