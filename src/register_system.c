/************************
 *
 * ����һ���Һż�¼
 *
 */
#include <stdio.h>
#include "ms.h"
#include <string.h>

int addRedRecording(PatientInfo *p){

    PatientInfo temp_pi;

    puts("�����벡��������");
    gets(temp_pi.Name);
    puts(temp_pi.Name);

    printf("�����벡�����֤�ţ�\n");
    gets(temp_pi.CardID);
    puts(temp_pi.CardID);

    puts("�����벡�����䣺");
    gets(temp_pi.Age);
    puts(temp_pi.Age);

    puts("�����벡���Ա�");
    gets(temp_pi.Sex);
    puts(temp_pi.Sex);

    for (int i = 0; i < 5; ++i) {

        puts("������Һſ��ұ�ţ�");
        temp_pi.R_ID = (int)getNum();

        puts("������Һ�ҽ����ţ�");
        temp_pi.D_ID = (int)getNum();

        temp_pi.ID = (long long)getTime() * 1000 + p_list_length + 1;
//    printf("%lld\n",temp_pi.ID);

        //�����������ȷ
        memcpy(p + p_list_length,&temp_pi,sizeof(temp_pi));//��ʱ�ṹ�帳��pָ�������Ԫ��
        printf("�Һű��Ϊ��%lld\n",p[p_list_length].ID);
        puts("***********�Һųɹ�********");
        p_list_length++;
//    printf("%lld\n",p->ID);
        puts("�û����Ƿ���Ҫ�����Һţ�1.��/2.�񣩣�");
        if (getNum() == 2){
            return 1;
        }
    }
    puts("�û��߽��չҺ������Ѵ�5�����ޡ�");
    return 1;
}