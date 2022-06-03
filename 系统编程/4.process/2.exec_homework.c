/*************************************************************************
	> File Name: 2.exec_homework.c
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Aug 2021 08:48:25 PM CST
 ************************************************************************/

#include "head.h"

int main(int argc, char **argv){
    //1.打开当前的文件夹opendir, 读文件夹下的文件reddir
    //2.如果文件不存在，编译并执行，如果文件不存在，vim打开文件
    //3.保存退出,编译并执行
    if(argc == 1){
        fprintf(stderr, "Usage: ./%s filename!\n",argv[0]);
        exit(1);
    }
    DIR * dirname;
    dirname = opendir(".");
    struct dirent *dir;
    int flag = 0;
    while((dir = readdir(dirname)) != NULL){
        if(!strcmp(dir->d_name, argv[1])){
            flag = 1;
        }
    }
    pid_t pid;
    if(flag == 0){
        int fd;
        if((fd = open(argv[1], O_RDWR | O_CREAT, 0644)) < 0 ){
            perror("open");
            exit(1);
        }
        if((pid = fork()) < 0){
            perror("fork");
            exit(1);
        }
        if(pid == 0){
            execl("/usr/bin/vim", "vim", argv[1], NULL);
        }
    }           
    wait(NULL);
    if((pid = fork()) < 0){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        execl("/usr/bin/gcc", "gcc", argv[1], "-o", "test.out", NULL);
    }else{
        wait(NULL);
        if((pid = fork()) < 0){
            perror("fork2");
            exit(1);
        }
        if(pid == 0){
            execl("/home/liu98/系统编程/4.process/test.out", "test.out", NULL);
        }else{
            wait(NULL);
            printf("I am the father!\n");
        }
    
    }
    return 0;
}

