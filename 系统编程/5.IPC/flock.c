/*************************************************************************
	> File Name: flock.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Aug 2021 01:46:45 PM CST
 ************************************************************************/

#include "head.h"

struct data{
    int now;
    int sum;
};

void getnum(struct data *num){
    int fd;
    if((fd = open(".data", O_RDONLY) < 0)){
        perror("get_open");
        exit(1);
    }
    read(fd, (void *)num, sizeof(struct data));
    close(fd);
}


void setnum( struct data *num){
    int fd;
    if((fd = open(".data", O_RDWR | O_CREAT, 0600)) < 0){
        perror("set_open");
        exit(1);
    }
    write(fd, (void *)num, sizeof(struct data));
    close(fd);
}


void do_sum(struct data *num, int max){
    int fd_lock;
    if((fd_lock = open(".lock", O_RDONLY)) < 0){
        perror("lock_open");
        exit(1);
    }
    while(1){
        flock(fd_lock, LOCK_EX);
        getnum(num);
        if(num->now >= max){
            break;
        }
        num->now++;
        num->sum += num->now;
        setnum(num);
        printf("now = %d, sum = %d\n", num->now, num->sum);
        flock(fd_lock, LOCK_UN);
    }
    close(fd_lock);
}


int main(int argc, char **argv){
    //多个进程实现求和计算
    //计算从0-n的和,m个进程
    //flock
    //一个进程访问文件时,加上锁,同一时刻，只有一个进程持有这个文件
    //文件:当前已经计算到哪个数字,当前的sum
    //./a.out -i m -n n
    int opt;
    int ins = 1, max = 100;
    struct data num;
    num.now = 0;
    num.sum = 0;
    setnum(&num);
    while((opt = getopt(argc, argv, "i:n:")) != -1){
        switch(opt){
            case 'i' :
                ins = atoi(optarg);
                break;
            case 'n' :
                max = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s -i num1 -n num2", argv[0]);
                exit(1);
        }
    }
    pid_t pid;
    int i;
    for(i = 1; i <= ins; i++){
        if((pid = fork()) < 0){
            perror("fork()");
            exit(1);
        }
        if(pid == 0){
            break;
        }
    }
    if(pid == 0){
        do_sum(&num, max);
        printf("I am the %d child\n", i);
    }else{
        for(int i = 1; i <= ins; i++){
            wait(NULL);
        }
    } 
    return 0;
}
