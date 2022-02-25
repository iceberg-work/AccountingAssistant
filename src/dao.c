//
// Created by iceberg-work on 2022/2/25.

#include "fileNameAndQuantity.h"
#include "dataText.h"
#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>

//1.判断给定路径是否存在且有写入权
/*
 * pathName 路径名
 * 返回值 存在：1；不存在：0；
 */
int hasPathExists(char* pathName) {
    /* Check for existence */
    if( (_access( pathName, 0 )) != -1 )
    {
        /* Check for write permission */
        if( (_access( "ACCESS.C", 2 )) != -1 )
            return 1;   //路径存在且有写入权
    }
    return 0;
}
//2.创建给定路径（依赖1）
/*
 * pathName 路径名
 * 返回值 成功：1；失败：0；
 */
int createPath(char* pathName) {
    int i,len;
    char str[512];
    strncpy(str, muldir, 512);
    len=strlen(str);
    for( i=0; i<len; i++ )
    {
        if( str[i]=='/' )
        {
            str[i] = '\0';
            if( access(str,0)!=0 )
            {
                mkdir( str, 0777 );
            }
            str[i]='/';
        }
    }
    if( len>0 && access(str,0)!=0 )
    {
        mkdir( str, 0777 );
    }
    return 1;   //不会有失败的情况
}
//3.读取给定路径下给定文件中的文本
/*
 * pathName 路径名
 * fileName 文件名
 * 返回值 读取到的内容
 */
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