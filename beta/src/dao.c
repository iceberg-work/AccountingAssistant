//
// Created by iceberg-work on 2022/2/26.

//#include "fileNameAndQuantity.h"
//#include "dataText.h"
#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>
#define maxlen 1024 

//3.读取给定路径下给定文件中的一行文本
/*
 * pathAndFileName 路径名及文件名
 * 返回值 读取到的内容
 */
int readByPath(char* pathName) {
    //创建文件流
    FILE *fp=fopen(pathName,"r");

    //2:检测文件是否打开成功；
    if(!fp){
        printf("打开失败！\n");
        return -1; //返回异常
    }
    char str[maxlen];//缓冲区，用来储存数据

    //从文件中读取一行数据，储存到str开始的地址,最大长度为maxlen，然后下次读取从下行开始
    //如果该行的数据长于maxlen-1,则只能返回一个不完整的行，并下次调用时从该处开始
    do {
        fgets(str,maxlen,fp);//存数据的末尾要有两个空行才可以读到'\0'
        printf("%s\n",str);
    } while (*str != '\0')
    fgets(str,maxlen,fp);
    //fgets(str,maxlen,fp);//存数据的末尾要有两个空行才可以读到'\0'
    //检测结果
    //关闭流
    fclose(fp);
    return 0;
}
//4.修改给定路径下给定文件中的文本
/*
 * pathName 路径名
 * fileName 文件名
 * newText 替换文本
 * ordinalOfPow 替换行的序号
 * 返回值 成功：1；失败：0；
 */
int updateByPath(char* pathName, char* fileName, char* newText, int ordinalOfRow);
//5.在给定路径下给定文件中的文本中写入数据
/*
 * pathName 路径名
 * fileName 文件名
 * 返回值 成功：1；失败：0；
 */
int writeByPath(char* pathName, char* fileName);
//6.读取给定路径下文件名称及数量（依赖1）
/*
 * pathName 路径名
 * 返回值 结构体指针；
 */
struct fileNameAndQuantity* getfileNameAndQuantity(char* pathName);

//
