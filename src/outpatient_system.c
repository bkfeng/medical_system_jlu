#include <ctype.h>
#include <stdio.h>
#include "ms.h"
#include <stdlib.h>
#include <string.h>
extern int p_list_length;
extern PatientInfo p_list[];

/**********
 *
 * @return 1����ȷ��  0������
 */
int outpatientSystem(){

    int os_quit_flag = 0;//����ϵͳ�˳����
    char time_now[8];//ʱ���ַ���

    PatientInfo *p = &p_list[p_list_length];
    char c_input[100];//�ַ�������
    char sc_input;//�����ַ�����
    int i_input;

    while (!os_quit_flag){

        system("cls");
        puts("*************��ӭ��������ϵͳ**************");
        puts("");
        puts("**********��ѡ����Ҫ���еĲ�����***********");
        puts("          1---�Һ�                      ");
        puts("          2---���                      ");
        puts("          3---��ҩ                      ");
        puts("          4---����                      ");
        puts("          5---��ѯ                      ");
        puts("          0---�����ϲ�                   ");

        while (1){

            gets(c_input);//��ȡ���벢�ж��ַ�������
            while (strlen(c_input) > 1){
                puts("*********�����������������**********");
                gets(c_input);
            }

            switch (c_input[0]) {

                case '1':
                    if (addPatientInfo(p)){//���ӹҺż�¼
                        system("pause");//�����������
                    } else{
                        puts("***********�������������ѡ��********");
                        system("pause");//�����������
                    }
                    break;
                case '2':
//                    iSystem();//����ҽ��ϵͳ
                    break;
                case '3':

                case '4':
                    if (savePatientInfo()){//����Һż�¼
                        system("pause");//�����������
                    } else{

                        system("pause");//�����������
                    }
                case '5':
                    os_quit_flag = 1;//�˳�ϵͳ
                    break;
                default:
                    puts("*********�����������������**********");
            }

            if (c_input[0] == '1' || c_input[0] == '2' || c_input[0] == '3'){
                break;
            }
        }

    }

    return 0;
}