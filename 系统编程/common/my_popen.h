/*************************************************************************
	> File Name: ../../common/my_popen.h
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Aug 2021 09:33:19 PM CST
 ************************************************************************/

#ifndef _../../COMMON/MY_POPEN_H
#define _../../COMMON/MY_POPEN_H
FILE* my_popen(const char* command, const char *type);
int my_pclose(FILE *fp);
#endif
