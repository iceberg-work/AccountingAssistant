//
// Created by iceberg-work on 2022/2/25.
//

#include "dataText.h"
#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>

struct dataText* readByPath(char* pathName, char* fileName) {
    //创建文件流
    FILE *fp=fopen(pathName,"r");

    //2:检测文件是否打开成功；
    if(!fp){
        const char* data= strcat(pathName, strcat(fileName,"打开失败")); //利用库函数连接三个字符串
        struct dataText* false = malloc(sizeof(struct dataText));
        false->data = data;
        return false; //返回异常
    }
    char str[1024];//缓冲区，用来储存数据

    //从文件中读取一行数据，储存到str开始的地址,最大长度为maxlen，然后下次读取从下行开始
    //如果该行的数据长于maxlen-1,则只能返回一个不完整的行，并下次调用时从该处开始
    fgets(str,1024,fp);

    //检测结果
    //printf("%s\n",str);
    sturct dataText* head = malloc(sizeof(dataText));
    sturct dataText* next = malloc(sizeof(dataText));
    head->next = next;
    while(1) {
        str = fgets(str,1024,fp);
        if (*str == '\0') break;
        next->data = str;
    }

    //关闭流
    fclose(fp);
    return 0;
}
//
