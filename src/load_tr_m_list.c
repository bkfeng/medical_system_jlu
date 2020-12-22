#include <stdio.h>
#include "ms.h"

extern TreatMed tr_m_list[];//诊疗记录  开药
extern int tr_m_list_length;//诊疗记录长度

extern double g_sum;

/**************
 * 功能：加载历史开药记录
 * @return 1成功  0失败
 */
int loadTreatMedList(){

    tr_m_list_length = 0;
    FILE *fp;
    fp = fopen("../data/tr_m_list.dat","ab+");
    if (fp == NULL){
        puts("开药记录导入失败失败！");
        return 0;
    }
    while (!feof(fp)){
        fread(&tr_m_list[tr_m_list_length], sizeof(TreatMed), 1, fp);
        if (tr_m_list[tr_m_list_length].PatientID){//判断读入记录是否为空
            g_sum += tr_m_list[tr_m_list_length].Total;
            tr_m_list_length ++;
        }

    }
    fclose(fp);
    printf("%d条开药记录已导入。\n", tr_m_list_length);

    return 1;
}