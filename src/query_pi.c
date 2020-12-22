#include "ms.h"
#include <stdio.h>
#include <string.h>

extern TreatMed tr_m_list[];//诊疗记录
extern int tr_m_list_length;//诊疗记录长度
extern Medicine m_list[];

extern TreatCheck tr_c_list[];//诊疗记录
extern int tr_c_list_length;//诊疗记录长度
extern Medicine c_list[];

extern int p_list_length;
extern PatientInfo p_list[];

int queryTreatMedPatientInfo(TreatMed *p){

    int ti = 0;
    long long t[100];

    char c[20];
    puts("请输入患者身份证号");
    stringInput(c,18,1);

    puts("该患者开药记录为：");
    puts(HEAD3);

    for (int i = 0; i < p_list_length; ++i) {
        if (strcmp(p_list[i].CardID,c) == 0){    //判断card id是否相等

            for (int j = 0; j < tr_m_list_length; ++j) {

                if (tr_m_list[j].PatientID == p_list[i].ID &&
                tr_m_list[j].Flag == 1){           //筛选符合挂号编号的记录并检查标志位是否有效

                    t[ti] = tr_m_list[j].ID;
                    ti++;
                    printf("|%3d.",ti);
                    printf(FORMAT3,DATA3);

                }
            }
        }
    }

    puts("该患者检查记录为：");
    puts(HEAD4);

    for (int i = 0; i < p_list_length; ++i) {
        if (strcmp(p_list[i].CardID,c) == 0){    //判断card id是否相等

            for (int j = 0; j < tr_c_list_length; ++j) {

                if (tr_c_list[j].PatientID == p_list[i].ID &&
                tr_c_list[j].Flag == 1){         //筛选符合挂号编号的记录并检查标志位是否有效

                    t[ti] = tr_c_list[j].ID;
                    ti++;
                    printf("|%3d.",ti);
                    printf(FORMAT4,DATA4);

                }
            }
        }
    }

    puts("退出请输入“0”。如需对诊疗记录进行修改或删除，请输入记录对应序号：\n");
    int i = getNum();
    if (i){
        modifyTreatList(t[i-1]);
    }
    return 1;

}