#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ms.h"

extern TreatCheck tr_c_list[];//���Ƽ�¼
extern int tr_c_list_length;//���Ƽ�¼����
extern int tr_c_list_length_new;//�������Ƽ�¼����
extern CheckUp c_list[];//ҩƷ��Ϣ

extern PatientInfo p_list[];//������Ϣ����
extern int p_list_length;//������Ϣ���鳤��
extern int p_list_length_new;//����������Ϣ���鳤��

extern double g_sum;

int addTreatCheList(TreatCheck *p){

    TreatCheck tr_temp;
    tr_temp.Flag = 1;
    int f = 0;
    int q = 0;
    char temp[255];

    puts("������Һű�ţ�");
    stringInput(temp,11,1);
    tr_temp.PatientID = strtoll(temp,NULL,10);
    for (int i = 0; i < p_list_length; ++i) {
        if (p_list[i].ID == tr_temp.PatientID){
            q = 1;
        }
    }
    if (!q){
        puts("�ñ�Ų����ڣ�");
        return 0;
    }

    do {

        puts("����������Ŀ��ţ�");
        stringInput(temp,2,1);
        tr_temp.C_ID = (int)strtol(temp,NULL,10);

        puts("������������");
        stringInput(temp,2,1);
        tr_temp.Num = (int)strtol(temp,NULL,10);

        tr_temp.Total = c_list[tr_temp.C_ID].Unit * tr_temp.Num;//�����ܶ�
        g_sum += tr_temp.Total;//��¼��ҽԺ��Ӫ����

        tr_temp.ID = (long long)getTime() * 10000 + tr_c_list_length + 1;//����ID

        //�����������ȷ
        memcpy(p + tr_c_list_length, &tr_temp, sizeof(tr_temp));//��ʱ�ṹ�帳��pָ�������Ԫ��

        puts("***********�����ɹ�********");
        tr_c_list_length++;
//    printf("%lld\n",p->ID);
        puts("�û����Ƿ���Ҫ������飨1.��/2.�񣩣�");

        f = getNum();
        if (f == 2){
            return 1;
        }
    } while (f == 1);

    puts("***********������********");
    return 1;
}

