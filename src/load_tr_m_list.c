#include <stdio.h>
#include "ms.h"

extern TreatMed tr_m_list[];//���Ƽ�¼  ��ҩ
extern int tr_m_list_length;//���Ƽ�¼����

extern double g_sum;

/**************
 * ���ܣ�������ʷ��ҩ��¼
 * @return 1�ɹ�  0ʧ��
 */
int loadTreatMedList(){

    tr_m_list_length = 0;
    FILE *fp;
    fp = fopen("../data/tr_m_list.dat","ab+");
    if (fp == NULL){
        puts("��ҩ��¼����ʧ��ʧ�ܣ�");
        return 0;
    }
    while (!feof(fp)){
        fread(&tr_m_list[tr_m_list_length], sizeof(TreatMed), 1, fp);
        if (tr_m_list[tr_m_list_length].PatientID){//�ж϶����¼�Ƿ�Ϊ��
            g_sum += tr_m_list[tr_m_list_length].Total;
            tr_m_list_length ++;
        }

    }
    fclose(fp);
    printf("%d����ҩ��¼�ѵ��롣\n", tr_m_list_length);

    return 1;
}