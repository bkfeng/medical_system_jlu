#include <stdio.h>
#include "ms.h"

extern int p_list_length;//������Ϣ���鳤��
extern PatientInfo p_list[];//������Ϣ����
int p_h_list_length;//������Ϣ��ʱ���鳤��

/**************
 * ���ܣ�����Һż�¼
 * @return 1�ɹ�  0ʧ��
 */
int savePatientInfo(){

    FILE *fp;
    fp = fopen("../data/patient_info.dat","ab+");
    if (fp == NULL){
        puts("�ļ�����ʧ�ܣ�");
        return 0;
    }
    for (int i = 0; i < p_list_length; ++i) {

        fwrite(&p_list[i],sizeof(PatientInfo),1,fp);
    }
    fclose(fp);
    printf("%d���Һż�¼�ѱ��档\n",p_list_length);
    p_list_length = 0;//�Һ����鳤������
//    loadPatientInfo();//���¶�ȡ�Һż�¼
    return 1;
}

