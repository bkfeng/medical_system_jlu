#include <stdio.h>
#include "ms.h"
#include <stdlib.h>
#include <string.h>

//ȫ�ֱ���
double g_sum = 0;//ҽԺ��Ӫ��
int is_save = 0;//�Ƿ��Ѿ�����

PatientInfo p_list[5000];//�Һż�¼���ѱ���
int p_list_length = 0;//������Ϣ��ʷ���鳤��
int p_list_length_new = 0;//����������Ϣ��ʷ���鳤��

TreatMed tr_m_list[5000];//���Ƽ�¼  ��ҩ
int tr_m_list_length = 0;//���Ƽ�¼����
int tr_m_list_length_new = 0;//�������Ƽ�¼����

TreatCheck tr_c_list[5000];//���Ƽ�¼  ���
int tr_c_list_length = 0;//���Ƽ�¼����
int tr_c_list_length_new = 0;//�������Ƽ�¼����

Medicine m_list[30] = {
        {
                0,"��Ī����",15
        },
        {
                1,"�п�",13.5
        }
};

CheckUp c_list[30] = {
        {
                0,"��͸",150
        },
        {
                1,"Ѫ����",60
        }
};

DoctorInfo d_list[10] = {
        {
                0,11,"����","����ҽʦ","��","0101010"
        },
        {
                1,12,"����","����ҽʦ","��","1010101"
        }
};

int main() {

    int quit_flag = 0;//ϵͳ�˳����
    char time_now[8];//ʱ���ַ���
    char c_input[100];//�ַ�������
    char sc_input;//�����ַ�����
    int i_input;

//    DoctorInfo *d_list = loadDoctorInfo();//��ȡҽ����Ϣ
//    m_list = loadMedicine();//��ȡҩƷ��Ϣ
//    CheckUp *c_list = loadCheckUp();

    /*----������ʷ��¼----*/
    loadPatientInfo();
    loadTreatMedList();
    loadTreatCheckList();
    system("pause");//�����������

    while (!quit_flag){

        system("cls");
        puts(HEAD0);
        puts("        ��ӭ���뼪�ִ�ѧҽ��ϵͳ         ");
        sprintf(time_now,"%d",getTime());//��ȡʱ�䲢ת��Ϊ�ַ���
        puts("");
        printf("         ��ǰϵͳʱ�䣺%s       \n",time_now);
        puts("");
        puts(HEAD1);
        puts("        ��ѡ����Ҫ�����ϵͳ��           ");
        puts(HEAD1);
        puts("          1---����ϵͳ                   ");
        puts("          2---סԺϵͳ                   ");
        puts("          #---�˳�ϵͳ                   ");
        puts(HEAD0);


        while (1){

            gets(c_input);//��ȡ���벢�ж��ַ�������
            while (strlen(c_input) > 1){
                puts("*********�����������������**********");
                gets(c_input);
            }

            switch (c_input[0]) {

                case '1':
                    outpatientSystem();//��������ϵͳ
                    break;
                case '2':
//                    inhosSystem();//����ҽ��ϵͳ
                    break;
                case '#':
                    quit_flag = 1;//�˳�ϵͳ
                    break;
                default:
                    puts("*********�����������������**********");
            }
            if (c_input[0] == '1' || c_input[0] == '2' || c_input[0] == '#'){
                break;
            }

        }

    }

    return 0;
}
