//
// Created by iceberg-work on 2022/2/25.
//

//������ʱ�� ������� ������Ŀ �������ݼ���ע ����ʱ�� ���� �Ƿ������
/*
 * Year of occurrence:yoo;
 * Month of occurrence:moo;
 * Day of occurrence:doo;
 * Year of bookkeeping:ybk;
 * Month of bookkeeping:mbk;
 * Day of bookkeeping:dbk;
 */
struct record {
    int yoo, moo, doo;
    int amountIncurred; //�������
    int AccountOccurs;  //������Ŀ
    char* specificContentAndRemarks;    //�������ݼ���ע
    int ybk, mbk, dbk;
    int ordinalOfRow;   //��ǰ�е����
    int hasExists;  //������1���Ѿ���ɾ����2��
};