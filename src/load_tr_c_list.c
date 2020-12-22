#include <stdio.h>
#include "ms.h"

extern TreatMed tr_c_list[];//���Ƽ�¼  ���
extern int tr_c_list_length;//���Ƽ�¼����

extern double g_sum;

/**************
 * ���ܣ�������ʷ����¼
 * @return 1�ɹ�  0ʧ��
 */
int loadTreatCheckList(){

    tr_c_list_length = 0;
    FILE *fp;
    fp = fopen("../data/tr_c_list.dat","ab+");
    if (fp == NULL){
        puts("����¼����ʧ��ʧ�ܣ�");
        return 0;
    }
    while (!feof(fp)){
        fread(&tr_c_list[tr_c_list_length], sizeof(TreatCheck), 1, fp);
        if (tr_c_list[tr_c_list_length].PatientID){//�ж϶����¼�Ƿ�Ϊ��
            g_sum += tr_c_list[tr_c_list_length].Total;
            tr_c_list_length ++;
        }

    }
    fclose(fp);
    printf("%d������¼�ѵ��롣\n", tr_c_list_length);

    return 1;
}