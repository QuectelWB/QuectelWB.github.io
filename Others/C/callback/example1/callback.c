/*
 * @Descripttion: 
 * @version: 
 * @Author: Smarthome Cloud Team
 * @Date: 2019-08-30 15:09:03
 * @LastEditors: jw.li
 * @LastEditTime: 2019-08-30 17:31:51
 */
#include <stdio.h>
#include "lib.h"

int mainCallbackPrintf(char *str){

	printf("[%s] This is main function, printf lib str: %s\n", __func__,str);
  	return 0;
}

int main(){
  	
	char* mainStr = "this is main str";
  	
	libPrintfFunction(mainStr, mainCallbackPrintf);
  return 0;
}
