/*************************************************************************
	> File Name: func_nonblock.c
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Aug 2021 07:23:50 PM CST
 ************************************************************************/

#include "head.h"

int main(){
    int num;
    int num1 = 12;
    int temp = 12;
    if((temp = make_nonblock(0)) < 0){
        perror("make_nonblock");
        exit(1);
    }
    scanf("%d", &num);
    if((temp = make_block(0)) < 0){
        perror("make_block");
        exit(1);
    }
    scanf("%d", &num1);
    printf("num = %d num1 = %d\n", num, num1);
    return 0;
}
