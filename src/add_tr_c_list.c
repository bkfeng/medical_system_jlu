#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ms.h"

extern TreatCheck tr_c_list[];//诊疗记录
extern int tr_c_list_length;//诊疗记录长度
extern int tr_c_list_length_new;//新增诊疗记录长度
extern CheckUp c_list[];//药品信息

extern PatientInfo p_list[];//病人信息数组
extern int p_list_length;//病人信息数组长度
extern int p_list_length_new;//新增病人信息数组长度

extern double g_sum;
extern int is_save;

int addTreatCheList(TreatCheck *p){

    TreatCheck tr_temp;
    tr_temp.Flag = 1;
    int f = 0;
    int q = 0;
    char temp[255];
    long long pid[5];

    puts("近5位患者编号分别为：");
    puts(HEAD5);
    for (int i = 0; i < 5; ++i) {
        if (p_list_length - i > 0){
            pid[i] = p_list[p_list_length - i].ID;
            int j = p_list_length -1 - i;
            printf(FORMAT5,DATA5);
        }
    }
    puts("请输入挂号编号(如果在上述记录中可直接输入序号)：");
    stringInput(temp,11,1);
    tr_temp.PatientID = strtoll(temp,NULL,10);

    if (tr_temp.PatientID <= 5){
        tr_temp.PatientID = pid[tr_temp.PatientID - 1];
    } else{
        for (int i = 0; i < p_list_length; ++i) {
            if (p_list[i].ID == tr_temp.PatientID){
                q = 1;
            }
        }
        if (!q){
            puts("该编号不存在！");
            return 0;
        }
    }

    do {

        puts("可选择的检查项目有:");
        puts("|编号  |名称    |单价  |");
        for (int i = 0; i < 6; ++i) {
            printf("|%4d.|%-8s|%6.2f|\n",i,c_list[i].Name,c_list[i].Unit);
        }
        puts("请输入检查项目编号：");
        stringInput(temp,2,1);
        tr_temp.C_ID = (int)strtol(temp,NULL,10);

        puts("请输入数量：");
        stringInput(temp,2,1);
        tr_temp.Num = (int)strtol(temp,NULL,10);

        tr_temp.Total = c_list[tr_temp.C_ID].Unit * tr_temp.Num;//计算总额
        g_sum += tr_temp.Total;//记录到医院总营收中

        tr_temp.ID = (long long)getTime() * 10000 + tr_c_list_length + 1;//生成ID
        printf("%lld\n",tr_temp.ID);

        //如果上述均正确
        memcpy(p + tr_c_list_length, &tr_temp, sizeof(tr_temp));//临时结构体赋给p指向的数组元素

        puts("***********操作成功********");
        tr_c_list_length++;

        is_save = 0;//设置为未保存状态

        puts("该患者是否需要继续检查（1.是/2.否）：");

        f = getNum();
        if (f == 2){
            return 1;
        }
    } while (f == 1);

    puts("***********检查结束********");
    return 1;
}

