//
// Created by iceberg on 2022/2/25.
// Copied by https://www.cnblogs.com/hongbo-tao/p/12050416.html

//test3.c
//�ж�ȡ�ļ�����

#include<stdio.h>
#define maxlen 30

int main()
{
    //�����ļ���
    FILE *fp=fopen("./data.txt","r");
    
    //2:����ļ��Ƿ�򿪳ɹ���
    if(!fp){
       printf("��ʧ�ܣ�\n");
       return -1; //�����쳣
    }
    char str[maxlen];//��������������������

    //���ļ��ж�ȡһ�����ݣ����浽str��ʼ�ĵ�ַ,��󳤶�Ϊmaxlen��Ȼ���´ζ�ȡ�����п�ʼ
    //������е����ݳ���maxlen-1,��ֻ�ܷ���һ�����������У����´ε���ʱ�Ӹô���ʼ
    fgets(str,maxlen,fp);
    fgets(str,maxlen,fp);
    fgets(str,maxlen,fp);
    fgets(str,maxlen,fp);//�����ݵ�ĩβҪ���������вſ��Զ���'\0' 
    //fgets(str,maxlen,fp);

    //�����
    printf("%s\n",str);

    //�ر���
    fclose(fp);
    return 0;

}
