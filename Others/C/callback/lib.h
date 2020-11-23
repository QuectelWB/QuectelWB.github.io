/*
 * @Descripttion: 
 * @version: 
 * @Author: Smarthome Cloud Team
 * @Date: 2019-08-30 17:01:29
 * @LastEditors: jw.li
 * @LastEditTime: 2019-08-30 17:41:23
 */
#ifndef _LIB_H_
#define _LIB_H_

typedef int (*libCallbackFunction_t)(char* str); //定义回调函数格式 为传入为char* return 为int的函数指针
int libPrintfFunction(char *str, libCallbackFunction_t callback);

#endif