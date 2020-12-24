#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ms.h"

extern TreatMed tr_m_list[];//���Ƽ�¼
extern int tr_m_list_length;//���Ƽ�¼����
//extern int tr_m_list_length_new;//�������Ƽ�¼����
extern Medicine m_list[];

extern PatientInfo p_list[];//������Ϣ����
extern int p_list_length;//������Ϣ���鳤��
//extern int p_list_length_new;//����������Ϣ���鳤��

extern double g_sum;
extern int is_save;

int addTreatMedList(TreatMed *p){

    TreatMed tr_temp;
    tr_temp.Flag = 1;
    int f;
    int q = 0;
    char temp[255];
    long long pid[5];

    puts("��5λ���߱�ŷֱ�Ϊ��");
    puts(HEAD5);
    for (int i = 0; i < 5; ++i) {
        if (p_list_length - i > 0){
            pid[i] = p_list[p_list_length - i].ID;
            int j = p_list_length -1 - i;
            printf(FORMAT5,DATA5);
        }
    }
    puts("������Һű��(�����������¼�п�ֱ���������)��");
    stringInput(temp,11,1);
    tr_temp.PatientID = strtoll(temp,NULL,10);

    if (tr_temp.PatientID <= 5){
        tr_temp.PatientID = pid[tr_temp.PatientID - 1];
    } else{
        for (int i = 0; i < p_list_length; ++i) {
            if (p_list[i].ID == tr_temp.PatientID){
                q = 1;
            }
        }
        if (!q){
            puts("�ñ�Ų����ڣ�");
            return 0;
        }
    }

    do {

        puts("��ѡ���ҩƷ��:");
        puts("|��� |����    |����  |");
        for (int i = 0; i < 6; ++i) {
            printf("|%4d.|%-8s|%6.2f|\n",i,m_list[i].Name,m_list[i].Unit);
        }
        puts("������ҩƷ��ţ�");
        stringInput(temp,2,1);
        tr_temp.M_ID = (int)strtol(temp,NULL,10);

        puts("������ҩƷ������");
        stringInput(temp,2,1);
        tr_temp.Num = (int)strtol(temp,NULL,10);

        tr_temp.Total = m_list[tr_temp.M_ID].Unit * tr_temp.Num;//�����ܶ�
        g_sum += tr_temp.Total;//��¼��ҽԺ��Ӫ����

        tr_temp.ID = (long long)getTime() * 10000 + 5000 + tr_m_list_length + 1;//����ID 5001-9999
        printf("%lld\n",tr_temp.ID);

        //�����������ȷ
        memcpy(p + tr_m_list_length, &tr_temp, sizeof(tr_temp));//��ʱ�ṹ�帳��pָ�������Ԫ��

        puts("***********�����ɹ�********");
        tr_m_list_length++;
        is_save = 0;
        puts("�û����Ƿ���Ҫ������ҩ��1.��/2.�񣩣�");

        f = getNum();
        if (f == 2){
            return 1;
        }
    } while (f == 1);

    puts("***********��ҩ����********");
    return 1;
}
