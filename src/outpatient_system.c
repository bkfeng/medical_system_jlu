/************************
 *      ����ϵͳ
 *
 */

#include <ctype.h>
#include <stdio.h>
#include "ms.h"
#include <stdlib.h>
#include <string.h>

int outpatientSystem(){

    int os_quit_flag = 0;//����ϵͳ�˳����
    char time_now[8];//ʱ���ַ���

    PatientInfo p_list[500];//������Ϣ����
    int p_list_length = 0 ;//������Ϣ���鳤��
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
        puts("          4---�����ϲ�                   ");

        while (1){

            sc_input = getchar();
            while (getchar() != '\n');//����������ʣ�ಿ��
            if (sc_input == '\n'){
                continue;
            }
            switch (sc_input) {

                case '1':
                    if (addRedRecording(p)){//���ӹҺż�¼
                        p_list_length++;
                        puts("***********�Һųɹ�********");
                        system("pause");//�����������
                    } else{
                        puts("***********�������������ѡ��********");
                    }
                    break;
                case '2':
//                    iSystem();//����ҽ��ϵͳ
                    break;
                case '3':

                case '4':
                    os_quit_flag = 1;//�˳�ϵͳ
                    break;
                default:
                    puts("*********�����������������**********");
            }

            if (sc_input == '1' || sc_input == '2' || sc_input == '3'){
                break;
            }
        }

    }

    return 0;
}