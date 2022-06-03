/*************************************************************************
	> File Name: 1.mkfifo.c
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Aug 2021 08:05:31 PM CST
 ************************************************************************/

#include "head.h"

int main(){
    int flag;

    if((flag = mkfifo("fifo_test", 0666)) < 0){
        if(errno == EEXIST){
            printf("fifo exist!\n");
        }else{
            perror("mkfifo");
            exit(1);
        }
    }
    int fd;
    if((fd = open("fifo_test", O_RDWR)) < 0){
        perror("open");
        exit(1);
    }
    char buff[20] = {0};
    write(fd, "hello kkb\n", 10);
    int n = read(fd, buff, 10);
    write(STDOUT_FILENO, buff, n);
    return 0;
}
