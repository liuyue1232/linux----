/*************************************************************************
	> File Name: ls.c
	> Author: 
	> Mail: 
	> Created Time: Sat 22 May 2021 04:04:36 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

extern int create_process (char* program, char** arg_list);

int main ()
{
    char* arg_list[] = {
                "ls",
                "-l",
                "/home/liu98/linux基础编程/",
                NULL
            
    };
        create_process ("ls", arg_list);
        return 0;

}

