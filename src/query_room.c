#include "ms.h"
#include <stdio.h>
#include <stdlib.h>

extern TreatMed tr_m_list[];//诊疗记录
extern int tr_m_list_length;//诊疗记录长度
extern Medicine m_list[];

extern TreatCheck tr_c_list[];//诊疗记录
extern int tr_c_list_length;//诊疗记录长度
extern Medicine c_list[];

extern int p_list_length;
extern PatientInfo p_list[];

int queryTreatRoom(){

    int ti = 0;
    long long t[100];
    int rid = 0;

    char c[20];
    puts("请输入科室编号");
    stringInput(c,2,1);
    rid = strtol(c,NULL,10);

    puts("该科室开药记录为：");
    puts(HEAD3);

    for (int i = 0; i < p_list_length; ++i) {
        if (p_list[i].R_ID == rid){    //判断room id是否相等

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

    puts("该科室检查记录为：");
    puts(HEAD4);

    for (int i = 0; i < p_list_length; ++i) {
        if (p_list[i].R_ID == rid){    //判断room id是否相等

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

