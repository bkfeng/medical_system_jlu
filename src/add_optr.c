#include <stdio.h>
#include "ms.h"


int addTreatmentRecord(TreatMed *p){

    TreatMed tr_temp;
    tr_temp.Flag = 1;

    puts("������Һű�ţ�");
    scanf("%lld",&tr_temp.PatientID);

    puts("������ҩƷ��ţ�");
    scanf("%d",&tr_temp.M_ID);

    puts("������ҩƷ������");
    scanf("%d",&tr_temp.Num);

    do {

        puts("������ҩƷ��ţ�");
        scanf("%d",&tr_temp.M_ID);

        puts("������ҩƷ������");
        scanf("%d",&tr_temp.Num);

        pi_temp.ID = (long long)getTime() * 1000 + p_list_length + 1;
//    printf("%lld\n",pi_temp.ID);

        //�����������ȷ
        memcpy(p + p_list_length, &pi_temp, sizeof(pi_temp));//��ʱ�ṹ�帳��pָ�������Ԫ��

        puts("***********��ҩ�ɹ�********");
        p_list_length++;
//    printf("%lld\n",p->ID);
        puts("�û����Ƿ���Ҫ������ҩ��1.��/2.�񣩣�");
        if (getNum() == 2){
            return 1;
        }
    } while (i == )
    puts("�û��߽��չҺ������Ѵ�5�����ޡ�");
}
