#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ms.h"
extern TreatMed tr_m_list[];
int queryOS() {

    int q_quit_flag = 0;//�����ѯϵͳ�˳����

    char c_input[100];//�ַ�������

    while (!q_quit_flag) {

        system("cls");
        puts("*************��ӭ���������ѯϵͳ**************");
        puts("");
        puts("**********��ѡ����Ҫ���еĲ�����***********");
        puts("          1---��ѯ�������Ƽ�¼                 ");
        puts("          2---��ѯ�������Ƽ�¼                     ");
        puts("          3---��ѯҽ�����Ƽ�¼                      ");
        puts("          4---��ѯĳʱ�����Ƽ�¼                    ");
        puts("          0---�����ϲ�                      ");

        while (1) {

            gets(c_input);//��ȡ���벢�ж��ַ�������
            while (strlen(c_input) > 1) {
                puts("*********�����������������**********");
                gets(c_input);
            }

            switch (c_input[0]) {

                case '1':
                    if (queryTreatPatientInfo()) {//��ѯ��¼
                        system("pause");//�����������
                    } else {
                        puts("***********�������������ѡ��********");
                        system("pause");//�����������
                    }
                    break;
                case '2':
                    if (queryTreatRoom()) {//��ѯ��¼
                        system("pause");//�����������
                    } else {
                        puts("***********�������������ѡ��********");
                        system("pause");//�����������
                    }
                    break;
                case '3':
                    if (queryTreatDoctor()) {//��ѯ��¼
                        system("pause");//�����������
                    } else {
                        puts("***********�������������ѡ��********");
                        system("pause");//�����������
                    }
                    break;
                case '4':
                    if (queryTreatTime()) {//��ѯ��¼
                        system("pause");//�����������
                    } else {
                        puts("***********�������������ѡ��********");
                        system("pause");//�����������
                    }
                    break;
                case '0':
                    q_quit_flag = 1;//�˳�ϵͳ
                    break;
                default:
                    puts("*********�����������������**********");
            }

            if (c_input[0] >= '0') {
                break;
            }
        }

    }
    return 1;
}


