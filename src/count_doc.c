#include "ms.h"
#include <stdio.h>

extern DoctorInfo d_list[];

extern TreatCheck tr_c_list[];//诊疗记录
extern int tr_c_list_length;//诊疗记录长度
//extern int tr_c_list_length_new;//新增诊疗记录长度
extern CheckUp c_list[];//药品信息

extern TreatMed tr_m_list[];//诊疗记录
extern int tr_m_list_length;//诊疗记录长度
//extern int tr_m_list_length_new;//新增诊疗记录长度
extern Medicine m_list[];

extern PatientInfo p_list[];//病人信息数组
extern int p_list_length;//病人信息数组长度
//extern int p_list_length_new;//新增病人信息数组长度

int countDoctor() {

    puts("医生接诊情况为：");
    puts("|    |      |    |        |            |出诊日期（●：出诊）|");
    puts("|工号|姓名  |科室|级别    |当日接诊人数|一|二|三|四|五|六|日|");
    for (int i = 0; i < 6; ++i) {
        int count = 0;
        for (int j = 0; j < p_list_length; ++j) {
            if (d_list[i].ID == p_list[j].D_ID && (p_list[j].ID / 10000000) == (getTime() / 10000)) {
                count++;
            }
        }
        printf("|%4d|%-6s|%4d|%-8s|%-12d|", d_list[i].ID, d_list[i].Name, d_list[i].RoomID, d_list[i].Level, count);
        for (int j = 0; j < 7; ++j) {
            if (d_list[i].Date[j] == '1') {
                printf("%-2s", "●|");
            } else {
                printf("%-2s", "○|");
            }
        }
        printf("\n");

    }
    return 1;
}
