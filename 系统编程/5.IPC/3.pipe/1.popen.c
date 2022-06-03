/*************************************************************************
	> File Name: 1.popen.c
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Aug 2021 08:17:41 PM CST
 ************************************************************************/

#include "head.h"

int main(){
    //popen pclose 实现用cat查看当前文件,并打印出来
    FILE *file;
    if((file = popen("/bin/cat ./1.popen.c", "r")) == NULL){
        perror("popen");
        exit(1);
    }
    size_t readsize;
    char buff[1024] = {0};
    while(readsize = fread(buff, 1, sizeof(buff), file)){
        printf("%s", buff);
    }
    pclose(file);

    
    return 0;
}
