#include <stdio.h>
#include "ms.h"
#include <stdlib.h>
#include <string.h>
#define HEAD0 "*****************************************"
#define HEAD1 "-----------------------------------------"
#define HEAD2 "|�Һű��|����|����|�Ա�|����|ҽ��|"
#define FORMAT "|% "
#define HEAD3 "|����|����|����|�ܼ�|"

//ȫ�ֱ���
int g_sum = 0;//ҽԺ��Ӫ��
int is_save = 0;//�Ƿ��Ѿ�����

PatientInfo p_h_list[5000];//������Ϣ��ʷ���飬�ѱ���
int p_h_list_length = 0;//������Ϣ��ʷ���鳤��

PatientInfo p_list[500];//������Ϣ��ʱ���飬δ����
int p_list_length = 0;//������Ϣ��ʱ���鳤��

int main() {

    int quit_flag = 0;//ϵͳ�˳����
    char time_now[8];//ʱ���ַ���
    char c_input[100];//�ַ�������
    char sc_input;//�����ַ�����
    int i_input;

    DoctorInfo *d_list = loadDoctorInfo();//��ȡҽ����Ϣ
    Medicine *m_list = loadMedicine();//��ȡҩƷ��Ϣ
    CheckUp *c_list = loadCheckUp();

    loadPatientInfo();

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
