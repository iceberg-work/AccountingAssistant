//
// Created by iceberg on 2022/2/25.
// Copied by https://www.cnblogs.com/hongbo-tao/p/12050416.html

//test3.c
//行读取文件数据

#include<stdio.h>
#define maxlen 30

int main()
{
    //创建文件流
    FILE *fp=fopen("./data.txt","r");
    
    //2:检测文件是否打开成功；
    if(!fp){
       printf("打开失败！\n");
       return -1; //返回异常
    }
    char str[maxlen];//缓冲区，用来储存数据

    //从文件中读取一行数据，储存到str开始的地址,最大长度为maxlen，然后下次读取从下行开始
    //如果该行的数据长于maxlen-1,则只能返回一个不完整的行，并下次调用时从该处开始
    fgets(str,maxlen,fp);
    fgets(str,maxlen,fp);
    fgets(str,maxlen,fp);
    fgets(str,maxlen,fp);//存数据的末尾要有两个空行才可以读到'\0' 
    //fgets(str,maxlen,fp);

    //检测结果
    printf("%s\n",str);

    //关闭流
    fclose(fp);
    return 0;

}
