#include <stdio.h>
#include "ms.h"
#include <stdlib.h>
#include <string.h>
extern int p_list_length;
extern PatientInfo p_list[];

extern int tr_m_list_length;
extern TreatMed tr_m_list[];

extern int tr_c_list_length;
extern TreatCheck tr_c_list[];
extern double g_sum;
/**********
 * ����ϵͳ
 * @return 1����ȷ��  0������
 */
int outpatientSystem(){

    int os_quit_flag = 0;//����ϵͳ�˳����

    PatientInfo *p = p_list;
    TreatMed *m = tr_m_list;
    TreatCheck *c = tr_c_list;

    char c_input[100];//�ַ�������

    while (!os_quit_flag){

        system("cls");
        puts("*************��ӭ��������ϵͳ**************");
        puts("");
        puts("**********��ѡ����Ҫ���еĲ�����***********");
        puts("          1---�Һ�                      ");
        puts("          2---���                      ");
        puts("          3---��ҩ                      ");
        puts("          4---����                      ");
        puts("          5---��ѯ���༭                 ");
        puts("          6---����                      ");
        puts("          7---ҽ���������                 ");
        puts("          8---ͳ��ҽԺӪ��                 ");
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
                    if (addTreatCheList(c)){//���Ӽ���¼
                        system("pause");//�����������
                    } else{
                        puts("***********�������������ѡ��********");
                        system("pause");//�����������
                    }
                    break;
                case '3':
                    if (addTreatMedList(m)){//���ӿ�ҩ��¼
                        system("pause");//�����������
                    } else{
                        puts("***********�������������ѡ��********");
                        system("pause");//�����������
                    }
                    break;
                case '4':
                    if (savePatientInfo() && saveTreatMedLIst() && saveTreatCheckLIst()){//����Һż�¼�����Ƽ�¼
                        system("pause");//�����������
                    } else{
                        puts("***********�������������ѡ��********");
                        system("pause");//�����������
                    }
                    break;
                case '5':
                    if (queryOS()){//��ѯ���Ƽ�¼
                        system("pause");//�����������
                    } else{
                        puts("***********�������������ѡ��********");
                        system("pause");//�����������
                    }
                    break;
                case '6':
                    if (importTreatList()){//�������Ƽ�¼
                        system("pause");//�����������
                    } else{
                        puts("***********�������������ѡ��********");
                        system("pause");//�����������
                    }
                    break;
                case '7':
                    if (countDoctor()){//ͳ��ҽ������
                        system("pause");//�����������
                    } else{
                        puts("***********�������������ѡ��********");
                        system("pause");//�����������
                    }
                    break;
                case '8':
                    printf("��Ӫҵ��Ϊ��%.2f\n",g_sum);
                    system("pause");//�����������
                    break;
                case '0':
                    os_quit_flag = 1;//�˳�ϵͳ
                    break;
                default:
                    puts("*********�����������������**********");
            }

            if (c_input[0] >= '0'){
                break;
            }
        }

    }

    return 0;
}