#include "ms.h"
#include <stdio.h>

extern DoctorInfo d_list[];

extern TreatCheck tr_c_list[];//���Ƽ�¼
extern int tr_c_list_length;//���Ƽ�¼����
//extern int tr_c_list_length_new;//�������Ƽ�¼����
extern CheckUp c_list[];//ҩƷ��Ϣ

extern TreatMed tr_m_list[];//���Ƽ�¼
extern int tr_m_list_length;//���Ƽ�¼����
//extern int tr_m_list_length_new;//�������Ƽ�¼����
extern Medicine m_list[];

extern PatientInfo p_list[];//������Ϣ����
extern int p_list_length;//������Ϣ���鳤��
//extern int p_list_length_new;//����������Ϣ���鳤��

int countDoctor() {

    puts("ҽ���������Ϊ��");
    puts("|    |      |    |        |            |�������ڣ��񣺳��|");
    puts("|����|����  |����|����    |���ս�������|һ|��|��|��|��|��|��|");
    for (int i = 0; i < 6; ++i) {
        int count = 0;
        for (int j = 0; j < p_list_length; ++j) {
            if (d_list[i].ID == p_list[j].D_ID && (p_list[j].ID / 10000000) == (getTime() / 10000)) {
                count++;
            }
        }
        printf("|%4d|%-6s|%4d|%-8s|%-12d|", d_list[i].ID, d_list[i].Name, d_list[i].RoomID, d_list[i].Level, count);
        for (int j = 0; j < 7; ++j) {
            if (d_list[i].Date[j] == '1') {
                printf("%-2s", "��|");
            } else {
                printf("%-2s", "��|");
            }
        }
        printf("\n");

    }
    return 1;
}
