/*************************************************************************
	> File Name: 2.exec.c
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Aug 2021 08:27:32 PM CST
 ************************************************************************/

#include "head.h"

int main(){

    pid_t pid;
    int i;
    for(i = 1; i <= 2; i++){
        sleep(1);
        if((pid = fork()) < 0){
            perror("fork()");
            exit(1);
        }
        if(pid == 0 && i == 1){
            execl("/usr/bin/gcc", "gcc", "1.fork.c", "-I", "../common/", NULL);            
        }else if(pid == 0 && i == 2){
            execl("/home/liu98/系统编程/4.process/a.out", "./a.out", NULL);
        }
    }
    wait(NULL);
    printf("i am the father!\n");

    return 0;
}
