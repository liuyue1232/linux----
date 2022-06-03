/*************************************************************************
	> File Name: 1.pthread.c
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Aug 2021 07:46:27 PM CST
 ************************************************************************/

#include "head.h"

struct Arg{
    int age;
    char name[20];
};

void *print(void *arg){
    struct Arg *argtemp = (struct Arg *)arg;
    printf("hello ");
    

}


int main(){
    pthread_t thread;
    struct Arg arg;
    bzero(&arg, sizeof(arg));
    arg



    return 0;
}
