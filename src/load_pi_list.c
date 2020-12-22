#include <stdio.h>
#include "ms.h"

extern int p_list_length;//������Ϣ���鳤��
extern PatientInfo p_list[];//������Ϣ����

/**************
 * ���ܣ�������ʷ�Һż�¼
 * @return 1�ɹ�  0ʧ��
 */
int loadPatientInfo(){

    p_list_length = 0;
    FILE *fp;
    fp = fopen("../data/patient_info.dat","ab+");
    if (fp == NULL){
        puts("�Һż�¼����ʧ��ʧ�ܣ�");
        return 0;
    }
    while (!feof(fp)){
        fread(&p_list[p_list_length], sizeof(PatientInfo), 1, fp);
        if (p_list[p_list_length].ID){//�ж϶����¼�Ƿ�Ϊ��
            p_list_length ++;
        }
    }
    fclose(fp);
    printf("%d���Һż�¼�ѵ��롣\n", p_list_length);

    return 1;
}


