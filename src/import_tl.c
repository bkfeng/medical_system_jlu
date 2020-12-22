#include "ms.h"
#include <stdio.h>
#include <stdlib.h>
/*****
int importTreatList() {

    TreatMed tr_temp;
    tr_temp.Flag = 1;
    int f;
    char temp[255];

    puts("请输入挂号编号：");
    stringInput(temp, 11, 1);
    tr_temp.PatientID = strtoll(temp, NULL, 10);

    puts("请输入药品编号：");
    stringInput(temp, 2, 1);
    tr_temp.M_ID = (int) strtol(temp, NULL, 10);

    puts("请输入药品数量：");
    stringInput(temp, 2, 1);
    tr_temp.Num = (int) strtol(temp, NULL, 10);

    tr_temp.Total = m_list[tr_temp.M_ID].Unit * tr_temp.Num;//计算总额

    tr_temp.ID = (long long) getTime() * 10000 + tr_list_length + 1;

    //如果上述均正确
    memcpy(p + tr_list_length, &tr_temp, sizeof(tr_temp));//临时结构体赋给p指向的数组元素

    puts("***********操作成功********");
    tr_list_length++;
    FILE *fp
    fp = fopen("../data/treat_ml.txt", 'r');
    fscanf(fp, "%lld,%d,%d",)
}

*/