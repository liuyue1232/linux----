/*************************************************************************
	> File Name: 3_3_1.c
	> Author: 
	> Mail: 
	> Created Time: Sun 06 Jun 2021 11:32:03 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>


void sig_usr(int signo){
    if(signo == SIGUSR1){
        printf("hello usr1\n");
    }else{
        printf("收到未捕捉的信号\n");
    }
    return ;
}


int main(){
    if(signal(SIGUSR1, sig_usr) == SIG_ERR){
        printf("SIGUSR1无法捕捉\n");
    }
    for(;;){
        sleep(1);
        printf("休息一秒\n");

    }
    printf("再见\n");
    return 0;

}
