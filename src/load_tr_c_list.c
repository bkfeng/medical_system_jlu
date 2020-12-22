#include <stdio.h>
#include "ms.h"

extern TreatMed tr_c_list[];//诊疗记录  检查
extern int tr_c_list_length;//诊疗记录长度

extern double g_sum;

/**************
 * 功能：加载历史检查记录
 * @return 1成功  0失败
 */
int loadTreatCheckList(){

    tr_c_list_length = 0;
    FILE *fp;
    fp = fopen("../data/tr_c_list.dat","ab+");
    if (fp == NULL){
        puts("检查记录导入失败失败！");
        return 0;
    }
    while (!feof(fp)){
        fread(&tr_c_list[tr_c_list_length], sizeof(TreatCheck), 1, fp);
        if (tr_c_list[tr_c_list_length].PatientID){//判断读入记录是否为空
            g_sum += tr_c_list[tr_c_list_length].Total;
            tr_c_list_length ++;
        }

    }
    fclose(fp);
    printf("%d条检查记录已导入。\n", tr_c_list_length);

    return 1;
}