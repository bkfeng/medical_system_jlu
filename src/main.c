#include <stdio.h>
#include <ms.h>
#include <stdlib.h>

int main() {

    int quit_flag = 0;//ϵͳ�˳����

    char time_now[8];//ʱ���ַ���

    char c_input[100];//�ַ�������
    char sc_input;//�����ַ�����
    int i_input;

    while (!quit_flag){

        system("cls");
        puts("*********��ӭ���뼪�ִ�ѧҽ��ϵͳ**********");
        sprintf(time_now,"%d",getTime());//��ȡʱ�䲢ת��Ϊ�ַ���
        printf("*********��ǰϵͳʱ�䣺%s**********\n",time_now);
        puts("**********��ѡ����Ҫ�����ϵͳ��***********");
        puts("**********1---����ϵͳ*******************");
        puts("**********2---סԺϵͳ*******************");
        puts("**********#---�˳�ϵͳ*******************");

        while (1){
            sc_input = getchar();
            if (sc_input == '\n'){
                continue;
            }
            switch (sc_input) {

                case '1':
//                    outpatientSystem();//��������ϵͳ
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
            if (sc_input == '1' || sc_input == '2' || sc_input == '#'){
                break;
            }
            while (getchar() != '\n')//����������ʣ�ಿ��
                continue;
        }

    }

//    char Time[8];
//    sprintf(Time,"%d",getTime());//��ȡʱ�䲢ת��Ϊ�ַ���

    return 0;
}
