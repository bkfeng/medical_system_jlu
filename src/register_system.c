
#include <stdio.h>
#include "ms.h"
#include <string.h>

/************************
 *
 * ����һ���Һż�¼
 *
 */
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

    printf("������Һſ��ұ�ţ�\n");
    int RID =getNum();
    printf("%d",RID);
    if (RID == 0){
        return 0;
    }

    printf("������Һ�ҽ����ţ�\n");
    int DID = (int)getNum();
    if (DID == 0){
        return 0;
    }
    temp_pi.ID = (getTime() * 100 + RID) *100 + DID;
    printf("%I64d",temp_pi.ID);
    memcpy(p,&temp_pi,sizeof(temp_pi));//��ʱ�ṹ�帳��pָ�������
    return 1;
}