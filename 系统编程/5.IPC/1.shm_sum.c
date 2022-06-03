/*************************************************************************
	> File Name: 1.flock.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Aug 2021 03:27:31 PM CST
 ************************************************************************/

#include "head.h"

struct data{
    int now;
    int sum;
};


void do_sum(int i, struct data *num, int max) {
    while(1) {
        //判断，计算
        if(num->now >= max) {
            break;
        }
        num->now++;
        num->sum += num->now;
        printf("<i am the %d child> now = %d, sum = %d\n", i, num->now, num->sum);
    }
}




int main(int argc, char **argv){
    //多个进程实现求和计算
    //计算从0到n的和，m个进程
    //flock
    //文件：当前已经计算到哪个数字，当前的sum
    //同一时刻，只有一个进程持有这个文件
    //共享内存
    //
    //./a.out -i m -n n
    int opt;
    int ins = 1, max = 100;
    while((opt = getopt(argc, argv, "i:n:")) != -1) {
        switch(opt){
            case 'i':
                ins = atoi(optarg);
                break;
            case 'n':
                max = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -i num1 -n num2", argv[0]);
                exit(1);
        }
    }
    key_t key;
    int shmid;
    if((key = ftok("1.shm_sum.c", 2021)) == -1){
        perror("ftok()");
        exit(1);
    }
    if((shmid = shmget(key, sizeof(struct data), IPC_CREAT | 0600)) < 0){
        perror("shmget");
        exit(1);
    }
    struct data* share_memory= (struct data *)shmat(shmid,NULL,0);
    if(share_memory == (struct data *)-1){
        perror("shmat");
        exit(1);
    }
    share_memory->now = 0;
    share_memory->sum = 0;
    
    pid_t pid;
    int i;
    for(i = 0; i < ins; i++) {
        if((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if(pid == 0) {
            break;
        }
    }
    if(pid == 0) {
        do_sum(i, share_memory, max);
        //printf("i am the %d child\n", i);
    } else {
        for(int i = 0; i < ins; i++) {
            wait(NULL);
        }
    }
	return 0;
}
