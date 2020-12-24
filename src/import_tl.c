#include "ms.h"
#include <stdio.h>
#include <string.h>

extern TreatCheck tr_c_list[];//���Ƽ�¼  ���
extern int tr_c_list_length;//���Ƽ�¼����
//extern int tr_c_list_length_new;//�������Ƽ�¼����
extern CheckUp c_list[];//ҩƷ��Ϣ

extern TreatMed tr_m_list[];//���Ƽ�¼   ��ҩ
extern int tr_m_list_length;//���Ƽ�¼����
//extern int tr_m_list_length_new;//�������Ƽ�¼����
extern Medicine m_list[];

extern double g_sum;
int importTreatList() {

    TreatCheck tr_c_temp;
    TreatMed tr_m_temp;
    tr_c_temp.Flag = 1;
    tr_m_temp.Flag = 1;
    int count = 0;
    FILE *fp;

    /*----------�������¼-------------*/
    fp = fopen("../data/treat_cl.txt","r+");
    if (fp == NULL){
        puts("����¼����ʧ��ʧ�ܣ�");
        return 0;
    }
    while (!feof(fp)){

        fscanf(fp,"%lld,%d,%d",&tr_c_temp.PatientID,&tr_c_temp.C_ID,&tr_c_temp.Num);
        tr_c_temp.Total = c_list[tr_c_temp.C_ID].Unit * tr_c_temp.Num;
        g_sum += tr_c_temp.Total;//��¼��ҽԺ��Ӫ����

        if (tr_c_temp.PatientID){//�ж϶����¼�Ƿ�Ϊ��
            memcpy(&tr_c_list[tr_c_list_length],&tr_c_temp,sizeof(TreatCheck));
            tr_c_list_length ++;
            count++;
        }
    }
    fclose(fp);
    printf("%d������¼�ѵ��롣\n", count);

    /*----------���뿪ҩ��¼-------------*/
    count = 0;//����������
    fp = fopen("../data/treat_ml.txt","r+");
    if (fp == NULL){
        puts("��ҩ��¼����ʧ��ʧ�ܣ�");
        return 0;
    }
    while (!feof(fp)){

        fscanf(fp,"%lld,%d,%d",&tr_m_temp.PatientID,&tr_m_temp.M_ID,&tr_m_temp.Num);
        tr_m_temp.Total = m_list[tr_m_temp.M_ID].Unit * tr_m_temp.Num;
        g_sum += tr_m_temp.Total;//��¼��ҽԺ��Ӫ����

        if (tr_m_temp.PatientID){//�ж϶����¼�Ƿ�Ϊ��
            memcpy(&tr_m_list[tr_m_list_length],&tr_m_temp,sizeof(TreatMed));
            tr_m_list_length ++;
            count++;
        }
    }
    fclose(fp);
    printf("%d����ҩ��¼�ѵ��롣\n", count);

    return 1;
}
