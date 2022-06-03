/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Aug 2021 07:20:45 PM CST
 ************************************************************************/

#include "head.h"



int make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag |= O_NONBLOCK;
    if ((fcntl(fd, F_SETFL, flag)) < 0) {
        return -1;
    }
    return 0;
}

int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag &= ~O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flag) < 0) {
        return -1;
    }
    return 0;
}

