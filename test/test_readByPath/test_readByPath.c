//
// Created by iceberg-work on 2022/2/25.
//

#include "dataText.h"
#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>

struct dataText* readByPath(char* pathName, char* fileName) {
    //�����ļ���
    FILE *fp=fopen(pathName,"r");

    //2:����ļ��Ƿ�򿪳ɹ���
    if(!fp){
        const char* data= strcat(pathName, strcat(fileName,"��ʧ��")); //���ÿ⺯�����������ַ���
        struct dataText* false = malloc(sizeof(struct dataText));
        false->data = data;
        return false; //�����쳣
    }
    char str[1024];//��������������������

    //���ļ��ж�ȡһ�����ݣ����浽str��ʼ�ĵ�ַ,��󳤶�Ϊmaxlen��Ȼ���´ζ�ȡ�����п�ʼ
    //������е����ݳ���maxlen-1,��ֻ�ܷ���һ�����������У����´ε���ʱ�Ӹô���ʼ
    fgets(str,1024,fp);

    //�����
    //printf("%s\n",str);
    sturct dataText* head = malloc(sizeof(dataText));
    sturct dataText* next = malloc(sizeof(dataText));
    head->next = next;
    while(1) {
        str = fgets(str,1024,fp);
        if (*str == '\0') break;
        next->data = str;
    }

    //�ر���
    fclose(fp);
    return 0;
}
//
