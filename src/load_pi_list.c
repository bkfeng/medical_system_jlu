#include <stdio.h>
#include "ms.h"

extern int p_list_length;//病人信息数组长度
extern PatientInfo p_list[];//病人信息数组

/**************
 * 功能：加载历史挂号记录
 * @return 1成功  0失败
 */
int loadPatientInfo(){

    p_list_length = 0;
    FILE *fp;
    fp = fopen("../data/patient_info.dat","ab+");
    if (fp == NULL){
        puts("挂号记录导入失败失败！");
        return 0;
    }
    while (!feof(fp)){
        fread(&p_list[p_list_length], sizeof(PatientInfo), 1, fp);
        if (p_list[p_list_length].ID){//判断读入记录是否为空
            p_list_length ++;
        }
    }
    fclose(fp);
    printf("%d条挂号记录已导入。\n", p_list_length);

    return 1;
}


