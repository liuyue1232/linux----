/*************************************************************************
	> File Name: 1.fork.c
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Aug 2021 06:51:17 PM CST
 ************************************************************************/

#include "head.h"

int main(){
    pid_t pid;
    int i = 0;
    for(i = 1; i <= 10; i++){
        sleep(1);
        if((pid = fork()) < 0){
            perror("fork");
            exit(1);
         }
        if(pid == 0){
            break;
        }
    }
    if(pid == 0){
        printf("i am child, my number is %d, my fater is %d\n", i, getppid());
    }else{
        for(int j = 1; j <= 20; j++){
            wait(NULL);
        }        
        printf("i am father, myid = %d\n",getpid());
    }
    return 0;
}

