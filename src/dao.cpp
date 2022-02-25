//
// Created by iceberg-work on 2022/2/25.

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
char* readByPath(char* pathName, char* fileName);
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