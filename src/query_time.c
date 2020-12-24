#include "ms.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern TreatMed tr_m_list[];//���Ƽ�¼
extern int tr_m_list_length;//���Ƽ�¼����
extern Medicine m_list[];

extern TreatCheck tr_c_list[];//���Ƽ�¼
extern int tr_c_list_length;//���Ƽ�¼����
extern Medicine c_list[];

extern int p_list_length;
extern PatientInfo p_list[];

int queryTreatTime(){

    int ti = 0;
    long long t[100];
    int time_start = 0;
    int time_end = 0;

    char c[20];
    puts("���俪ʼʱ�䣨����12��20��18��35�������롱12201835������");
    stringInput(c,8,1);
    time_start = strtol(c,NULL,10);
    puts("�������ʱ�䣨����12��20��18��35�������롱12201835��������ǰʱ�������롱0����");
    stringInput(c,8,1);
    time_end = strtol(c,NULL,10);
    if (!time_end){
        time_end = getTime();
    }

    puts("��ʱ�ο�ҩ��¼Ϊ��");
    puts(HEAD3);

    for (int i = 0; i < p_list_length; ++i) {
        if (p_list[i].ID/1000 >= time_start && p_list[i].ID/1000 <= time_end){    //�ж�ʱ��

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

    puts("��ҽ������¼Ϊ��");
    puts(HEAD4);

    for (int i = 0; i < p_list_length; ++i) {
        if (p_list[i].ID/1000 >= time_start && p_list[i].ID/1000 <= time_end){    //�ж�ʱ��

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

