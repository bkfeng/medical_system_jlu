#include <stdio.h>
#include "ms.h"

extern int p_h_list_length;//������Ϣ���鳤��
extern PatientInfo p_h_list[];//������Ϣ����

/**************
 * ���ܣ�������ʷ�Һż�¼
 * @return 1�ɹ�  0ʧ��
 */
int loadPatientInfo(){

    p_h_list_length = 0;
    FILE *fp;
    fp = fopen("../data/patient_info.dat","rb");
    if (fp == NULL){
        puts("�Һż�¼����ʧ��ʧ�ܣ�");
        return 0;
    }
    while (!feof(fp)){
        fread(&p_h_list[p_h_list_length], sizeof(PatientInfo),1,fp);
        p_h_list_length ++;
    }
    fclose(fp);
    printf("%d���Һż�¼�ѵ��롣\n",p_h_list_length);

    return 1;
}


