/************************
 *      ����ϵͳ
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <ms.h>
#include <stdlib.h>
#include <string.h>

/************************
 *
 * ����һ���Һż�¼
 *
 */
int addOSRecording(PatientInfo *p){

    PatientInfo tempP;
    char c_temp[20]="12345";
    puts(c_temp);
    puts("�����벡��������");
    gets(c_temp);
    puts(c_temp);
    printf("�����벡�����֤�ţ�\n");
    strcpy(tempP.Name,c_temp);
    puts("�����벡�����䣺");
    tempP.Age = (int)getNum();
    if (tempP.Age == 0){
        return 0;
    }
    printf("�����벡�����֤�ţ�\n");
    tempP.CardID = getNum();
    if (tempP.CardID == 0){
        return 0;
    }
    printf("������Һſ��ұ�ţ�\n");
    int RID = (int)getNum();
    if (RID == 0){
        return 0;
    }
    printf("������Һ�ҽ����ţ�\n");
    int DID = (int)getNum();
    if (DID == 0){
        return 0;
    }
    tempP.ID = (getTime() * 100 + RID) *100 + DID;
    memcpy(p,&tempP,sizeof(tempP));//��ʱ�ṹ�帳��pָ�������
    return 1;

}

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
            if (sc_input == '\n'){
                continue;
            }
            switch (sc_input) {

                case '1':
                    if (addOSRecording(p)){//���ӹҺż�¼
                        p_list_length++;
                    } else{
                        puts("***********�������������ѡ��********");
                    }
                    break;
                case '2':
//                    iSystem();//����ҽ��ϵͳ
                    break;
                case '3':

                case '#':
                    os_quit_flag = 1;//�˳�ϵͳ
                    break;
                default:
                    puts("*********�����������������**********");
            }
            if (sc_input == '1' || sc_input == '2' || sc_input == '#'){
                break;
            }
            while (getchar() != '\n')//����������ʣ�ಿ��
                continue;
        }

    }

    return 0;
}