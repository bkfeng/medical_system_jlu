#include "ms.h"
#include <stdio.h>
#include <string.h>

extern TreatCheck tr_c_list[];//诊疗记录  检查
extern int tr_c_list_length;//诊疗记录长度
//extern int tr_c_list_length_new;//新增诊疗记录长度
extern CheckUp c_list[];//药品信息

extern TreatMed tr_m_list[];//诊疗记录   开药
extern int tr_m_list_length;//诊疗记录长度
//extern int tr_m_list_length_new;//新增诊疗记录长度
extern Medicine m_list[];

extern double g_sum;
int importTreatList() {

    TreatCheck tr_c_temp;
    TreatMed tr_m_temp;
    tr_c_temp.Flag = 1;
    tr_m_temp.Flag = 1;
    int count = 0;
    FILE *fp;

    /*----------导入检查记录-------------*/
    fp = fopen("../data/treat_cl.txt","r+");
    if (fp == NULL){
        puts("检查记录导入失败失败！");
        return 0;
    }
    while (!feof(fp)){

        fscanf(fp,"%lld,%d,%d",&tr_c_temp.PatientID,&tr_c_temp.C_ID,&tr_c_temp.Num);
        tr_c_temp.Total = c_list[tr_c_temp.C_ID].Unit * tr_c_temp.Num;
        g_sum += tr_c_temp.Total;//记录到医院总营收中

        if (tr_c_temp.PatientID){//判断读入记录是否为空
            memcpy(&tr_c_list[tr_c_list_length],&tr_c_temp,sizeof(TreatCheck));
            tr_c_list_length ++;
            count++;
        }
    }
    fclose(fp);
    printf("%d条检查记录已导入。\n", count);

    /*----------导入开药记录-------------*/
    count = 0;//计数器清零
    fp = fopen("../data/treat_ml.txt","r+");
    if (fp == NULL){
        puts("开药记录导入失败失败！");
        return 0;
    }
    while (!feof(fp)){

        fscanf(fp,"%lld,%d,%d",&tr_m_temp.PatientID,&tr_m_temp.M_ID,&tr_m_temp.Num);
        tr_m_temp.Total = m_list[tr_m_temp.M_ID].Unit * tr_m_temp.Num;
        g_sum += tr_m_temp.Total;//记录到医院总营收中

        if (tr_m_temp.PatientID){//判断读入记录是否为空
            memcpy(&tr_m_list[tr_m_list_length],&tr_m_temp,sizeof(TreatMed));
            tr_m_list_length ++;
            count++;
        }
    }
    fclose(fp);
    printf("%d条开药记录已导入。\n", count);

    return 1;
}
