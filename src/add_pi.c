#include <stdio.h>
#include "ms.h"
#include <string.h>
extern int p_list_length;//������Ϣ���鳤��
//extern int p_list_length_new;//����������Ϣ���鳤��
extern int is_save;

/*****************
 * ����һ���Һż�¼
 * @param p ���˼�¼����ָ��
 * @return 1����ȷ��  0������
 */

int addPatientInfo(PatientInfo *p){

    PatientInfo pi_temp;

    puts("�����벡��������");
    gets(pi_temp.Name);
//    puts(pi_temp.Name);

    puts("�����벡�����֤�ţ�");
    if (!stringInput(pi_temp.CardID,18,1)){
        return 0;
    }

    puts("�����벡�����䣺");
    if (!stringInput(pi_temp.Age,18,1)){
        return 0;
    }

    puts("�����벡���Ա�");
    gets(pi_temp.Sex);
//    puts(pi_temp.Sex);

    countDoctor();
    for (int i = 0; i < 5; ++i) {

        puts("������Һſ��ұ�ţ�");
        pi_temp.R_ID = (int)getNum();

        puts("������Һ�ҽ����ţ�");
        pi_temp.D_ID = (int)getNum();

        pi_temp.ID = (long long)getTime() * 1000 + p_list_length + 1;
//    printf("%lld\n",pi_temp.ID);

        //�����������ȷ
        memcpy(p + p_list_length, &pi_temp, sizeof(pi_temp));//��ʱ�ṹ�帳��pָ�������Ԫ��
        printf("�Һű��Ϊ��%lld\n",p[p_list_length].ID);
        puts("***********�Һųɹ�********");
        p_list_length++;
        is_save = 0;
        puts("�û����Ƿ���Ҫ�����Һţ�1.��/2.�񣩣�");
        if (getNum() == 2){
            return 1;
        }
    }
    puts("�û��߽��չҺ������Ѵ�5�����ޡ�");
    return 1;
}