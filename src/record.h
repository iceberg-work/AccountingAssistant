//
// Created by iceberg-work on 2022/2/25.
//

#ifndef ACCOUNTINGASSISTANT_RECORD_H
#define ACCOUNTINGASSISTANT_RECORD_H

//“发生时间 发生金额 发生科目 具体内容及备注 记账时间 行数 是否存续”
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
    int amountIncurred; //发生金额
    int AccountOccurs;  //发生科目
    char* specificContentAndRemarks;    //具体内容及备注
    int ybk, mbk, dbk;
    int ordinalOfRow;   //当前行的序号
    int hasExists;  //存续：1；已经被删除：2；
};

#endif //ACCOUNTINGASSISTANT_RECORD_H
