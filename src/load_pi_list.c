#include <stdio.h>
#include "ms.h"

extern int p_h_list_length;//病人信息数组长度
extern PatientInfo p_h_list[];//病人信息数组

/**************
 * 功能：加载历史挂号记录
 * @return 1成功  0失败
 */
int loadPatientInfo(){

    p_h_list_length = 0;
    FILE *fp;
    fp = fopen("../data/patient_info.dat","rb");
    if (fp == NULL){
        puts("挂号记录导入失败失败！");
        return 0;
    }
    while (!feof(fp)){
        fread(&p_h_list[p_h_list_length], sizeof(PatientInfo),1,fp);
        p_h_list_length ++;
    }
    fclose(fp);
    printf("%d条挂号记录已导入。\n",p_h_list_length);

    return 1;
}


