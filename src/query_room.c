#include "ms.h"
#include <stdio.h>
#include <stdlib.h>

extern TreatMed tr_m_list[];//���Ƽ�¼
extern int tr_m_list_length;//���Ƽ�¼����
extern Medicine m_list[];

extern TreatCheck tr_c_list[];//���Ƽ�¼
extern int tr_c_list_length;//���Ƽ�¼����
extern Medicine c_list[];

extern int p_list_length;
extern PatientInfo p_list[];

int queryTreatRoom(){

    int ti = 0;
    long long t[100];
    int rid = 0;

    char c[20];
    puts("��������ұ��");
    stringInput(c,2,1);
    rid = strtol(c,NULL,10);

    puts("�ÿ��ҿ�ҩ��¼Ϊ��");
    puts(HEAD3);

    for (int i = 0; i < p_list_length; ++i) {
        if (p_list[i].R_ID == rid){    //�ж�room id�Ƿ����

            for (int j = 0; j < tr_m_list_length; ++j) {

                if (tr_m_list[j].PatientID == p_list[i].ID &&
                    tr_m_list[j].Flag == 1){           //ɸѡ���ϹҺű�ŵļ�¼������־λ�Ƿ���Ч

                    t[ti] = tr_m_list[j].ID;
                    ti++;
                    printf("|%3d.",ti);
                    printf(FORMAT3,DATA3);

                }
            }
        }
    }

    puts("�ÿ��Ҽ���¼Ϊ��");
    puts(HEAD4);

    for (int i = 0; i < p_list_length; ++i) {
        if (p_list[i].R_ID == rid){    //�ж�room id�Ƿ����

            for (int j = 0; j < tr_c_list_length; ++j) {

                if (tr_c_list[j].PatientID == p_list[i].ID &&
                    tr_c_list[j].Flag == 1){         //ɸѡ���ϹҺű�ŵļ�¼������־λ�Ƿ���Ч

                    t[ti] = tr_c_list[j].ID;
                    ti++;
                    printf("|%3d.",ti);
                    printf(FORMAT4,DATA4);

                }
            }
        }
    }

    puts("�˳������롰0������������Ƽ�¼�����޸Ļ�ɾ�����������¼��Ӧ��ţ�\n");
    int i = getNum();
    if (i){
        modifyTreatList(t[i-1]);
    }
    return 1;

}

