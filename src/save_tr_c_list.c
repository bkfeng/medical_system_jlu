#include <stdio.h>
#include "ms.h"

extern int p_list_length;//������Ϣ���鳤��
extern PatientInfo p_list[];//������Ϣ����

extern TreatCheck tr_c_list[];//���Ƽ�¼  ��ҩ
extern int tr_c_list_length;//���Ƽ�¼����

/**************
 * ���ܣ��������Ƽ�¼  ���
 * @return 1�ɹ�  0ʧ��
 */
int saveTreatCheckLIst(){

    FILE *fp;
    fp = fopen("../data/tr_c_list.dat","wb+");//����д��
    if (fp == NULL){
        puts("�ļ�����ʧ�ܣ�");
        return 0;
    }
    for (int i = 0; i < tr_c_list_length; ++i) {

        fwrite(&tr_c_list[i],sizeof(TreatCheck),1,fp);
    }
    fclose(fp);
    printf("%d����ҩ��¼�ѱ��档\n",tr_c_list_length);
//    tr_m_list_length = 0;//���鳤������
//    loadPatientInfo();//���¶�ȡ�Һż�¼
    return 1;
}