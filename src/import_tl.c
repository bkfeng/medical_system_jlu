#include "ms.h"
#include <stdio.h>
#include <stdlib.h>
/*****
int importTreatList() {

    TreatMed tr_temp;
    tr_temp.Flag = 1;
    int f;
    char temp[255];

    puts("������Һű�ţ�");
    stringInput(temp, 11, 1);
    tr_temp.PatientID = strtoll(temp, NULL, 10);

    puts("������ҩƷ��ţ�");
    stringInput(temp, 2, 1);
    tr_temp.M_ID = (int) strtol(temp, NULL, 10);

    puts("������ҩƷ������");
    stringInput(temp, 2, 1);
    tr_temp.Num = (int) strtol(temp, NULL, 10);

    tr_temp.Total = m_list[tr_temp.M_ID].Unit * tr_temp.Num;//�����ܶ�

    tr_temp.ID = (long long) getTime() * 10000 + tr_list_length + 1;

    //�����������ȷ
    memcpy(p + tr_list_length, &tr_temp, sizeof(tr_temp));//��ʱ�ṹ�帳��pָ�������Ԫ��

    puts("***********�����ɹ�********");
    tr_list_length++;
    FILE *fp
    fp = fopen("../data/treat_ml.txt", 'r');
    fscanf(fp, "%lld,%d,%d",)
}

*/