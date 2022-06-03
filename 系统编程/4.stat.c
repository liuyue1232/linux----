/*************************************************************************
	> File Name: 4.stat.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Aug 2021 12:43:56 PM CST
 ************************************************************************/

#include "head.h"

int main(int argc, char **argv){
    char dir_name[256] = {0};
    if(argc == 1){
        strcpy(dir_name, ".");
    }else{
        strcpy(dir_name, argv[1]);
    }
    int stat_num;
    struct stat statbuf;
    if((stat_num = stat(dir_name, &statbuf)) == -1){
        perror("stat");
        exit(1);
    }
    printf("%ld %s\n", statbuf.st_ino, dir_name);
    return 0;
}
