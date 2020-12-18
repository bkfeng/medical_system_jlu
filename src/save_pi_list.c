#include <stdio.h>
#include "ms.h"

extern int p_list_length;//病人信息数组长度
extern PatientInfo p_list[];//病人信息数组
int p_h_list_length;//病人信息临时数组长度

/**************
 * 功能：保存挂号记录
 * @return 1成功  0失败
 */
int savePatientInfo(){

    FILE *fp;
    fp = fopen("../data/patient_info.dat","ab+");
    if (fp == NULL){
        puts("文件保存失败！");
        return 0;
    }
    for (int i = 0; i < p_list_length; ++i) {

        fwrite(&p_list[i],sizeof(PatientInfo),1,fp);
    }
    fclose(fp);
    printf("%d条挂号记录已保存。\n",p_list_length);
    p_list_length = 0;//挂号数组长度清零
//    loadPatientInfo();//重新读取挂号记录
    return 1;
}

