#include <stdio.h>
#include "ms.h"

extern int p_list_length;//病人信息数组长度
extern PatientInfo p_list[];//病人信息数组

extern TreatCheck tr_c_list[];//诊疗记录  开药
extern int tr_c_list_length;//诊疗记录长度

/**************
 * 功能：保存诊疗记录  检查
 * @return 1成功  0失败
 */
int saveTreatCheckLIst(){

    FILE *fp;
    fp = fopen("../data/tr_c_list.dat","wb+");//覆盖写入
    if (fp == NULL){
        puts("文件保存失败！");
        return 0;
    }
    for (int i = 0; i < tr_c_list_length; ++i) {

        fwrite(&tr_c_list[i],sizeof(TreatCheck),1,fp);
    }
    fclose(fp);
    printf("%d条开药记录已保存。\n",tr_c_list_length);
//    tr_m_list_length = 0;//数组长度清零
//    loadPatientInfo();//重新读取挂号记录
    return 1;
}