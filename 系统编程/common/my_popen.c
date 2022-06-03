/*************************************************************************
	> File Name: ../../common/my_popen.c
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Aug 2021 09:34:21 PM CST
 ************************************************************************/


#include "head.h"

FILE *my_popen(const char* command, const char *type){
    //1.pipe
    //2.fork
    //3.execl
    if((type[0] != 'r' || type[0] != 'w') || type[1] != 0){
        errno = EINVAL;
        return NULL;
    }
    int pipefd[2];
    if(pipe(pipefd) < 0){
        return NULL;
    }

    pid_t pid;
    if((pid = fork()) < 0){
        return NULL;
    }
    if(pid == 0){
        if(type[0] = 'r'){
            close(pipefd[0]);

        }
    }
    
}

int my_pclose(FILE *fp){
    //1.wait4
    //fclose
    



}
