/*************************************************************************
	> File Name: 1.ftok.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Aug 2021 04:41:10 PM CST
 ************************************************************************/

#include "head.h"


int main(){
    key_t key;
    int shmid;
    char * share_memory = NULL;
    pid_t pid;
    if((key = ftok("1.ftok.c", 123)) < 0){
        perror("ftok");
        exit(1);
    }
    printf("key = 0x%x\n", key);
    if((shmid = shmget(key, 4096, IPC_CREAT | 0666)) < 0){
        perror("shmget");
        exit(1);
    }
    if((share_memory = shmat(shmid, NULL, 0)) == (void *) -1){
        perror("shmat");
        exit(1);
    } 
    if((pid = fork()) < 0){
        perror("fork()");
        exit(1);
    }
    if(pid){
        while(1){
            printf("i am the father: \n");
            
            scanf("%[^\n]s",share_memory);
            getchar();
            sleep(2);
        }
    }else{
        while(1){
            if(strlen(share_memory)){
                printf("i am the child: %s\n", share_memory);
            }
            memset(share_memory, 0, 4096);
        }
    }
    int flag;
    if((flag = shmdt(share_memory)) < 0){
        perror("shmdt");
        exit(1);
    }
    if(pid){
        wait(NULL);
        if((flag = shmctl(shmid, IPC_RMID, NULL)) < 0){
            perror("shmctl");
            exit(1);
        }
    }
    return 0;
}
