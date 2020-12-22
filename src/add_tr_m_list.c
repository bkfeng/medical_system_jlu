#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ms.h"

extern TreatMed tr_m_list[];//诊疗记录
extern int tr_m_list_length;//诊疗记录长度
extern int tr_m_list_length_new;//新增诊疗记录长度
extern Medicine m_list[];

extern PatientInfo p_list[];//病人信息数组
extern int p_list_length;//病人信息数组长度
extern int p_list_length_new;//新增病人信息数组长度

extern double g_sum;

int addTreatMedList(TreatMed *p){

    TreatMed tr_temp;
    tr_temp.Flag = 1;
    int f = 0;
    int q = 0;
    char temp[255];

    puts("请输入挂号编号：");
    stringInput(temp,11,1);
    tr_temp.PatientID = strtoll(temp,NULL,10);
    for (int i = 0; i < p_list_length; ++i) {
        if (p_list[i].ID == tr_temp.PatientID){
            q = 1;
        }
    }
    if (!q){
        puts("该编号不存在！");
        return 0;
    }

    do {

        puts("请输入药品编号：");
        stringInput(temp,2,1);
        tr_temp.M_ID = (int)strtol(temp,NULL,10);

        puts("请输入药品数量：");
        stringInput(temp,2,1);
        tr_temp.Num = (int)strtol(temp,NULL,10);

        tr_temp.Total = m_list[tr_temp.M_ID].Unit * tr_temp.Num;//计算总额
        g_sum += tr_temp.Total;//记录到医院总营收中

        tr_temp.ID = (long long)getTime() * 10000 + 5000 + tr_m_list_length + 1;//生成ID 5001-9999

        //如果上述均正确
        memcpy(p + tr_m_list_length, &tr_temp, sizeof(tr_temp));//临时结构体赋给p指向的数组元素

        puts("***********操作成功********");
        tr_m_list_length++;
//    printf("%lld\n",p->ID);
        puts("该患者是否需要继续开药（1.是/2.否）：");

        f = getNum();
        if (f == 2){
            return 1;
        }
    } while (f == 1);

    puts("***********开药结束********");
    return 1;
}
