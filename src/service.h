//
// Created by iceberg-work on 2022/2/25.
//

#include "record.h"
#ifndef ACCOUNTINGASSISTANT_SERVICE_H
#define ACCOUNTINGASSISTANT_SERVICE_H

//1.判断闰年
/*
 * 返回值 是闰年：1；不是闰年：0；
 */
int hasLeapYears(int year);
//2.判断日期是否合理（依赖1）
/*
 * 返回值 合理：1；不合理：0；
 */
int hasDateWithinExpectedRange(int year, int month, int day);
//3.依据传入的int类型数字进行文本读写
/*
 * pathName 路径名
 * fileName 文件名
 * operand 读文本：1；写文本：2；修改文本：3；
 * 返回值 成功：1；失败：0；
 */
int ManipulateInText(char* pathName, char* fileName, int operand);
//4.将一个时间段的记录以指定格式读入到内存中（依赖8）

int getData();
//5.指定格式打印
//6.指定内容提示语
//7.返回或退出
//8.数据处理器
int dataProcessor();
//9.数据分析：科目开销总计及占比
//10.数据分析：恩格尔系数

#endif //ACCOUNTINGASSISTANT_SERVICE_H
