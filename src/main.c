#include <stdio.h>
#include <ms.h>
#include <stdlib.h>

int main() {

    int quit_flag = 0;//系统退出标记

    char time_now[8];//时间字符串

    char c_input[100];//字符串输入
    char sc_input;//单个字符输入
    int i_input;

    while (!quit_flag){

        system("cls");
        puts("*********欢迎进入吉林大学医疗系统**********");
        sprintf(time_now,"%d",getTime());//获取时间并转换为字符串
        printf("*********当前系统时间：%s**********\n",time_now);
        puts("**********请选择需要进入的系统：***********");
        puts("**********1---门诊系统*******************");
        puts("**********2---住院系统*******************");
        puts("**********#---退出系统*******************");

        while (1){
            sc_input = getchar();
            if (sc_input == '\n'){
                continue;
            }
            switch (sc_input) {

                case '1':
//                    outpatientSystem();//进入门诊系统
                    break;
                case '2':
//                    inhosSystem();//进入医疗系统
                    break;
                case '#':
                    quit_flag = 1;//退出系统
                    break;
                default:
                    puts("*********输入错误，请重新输入**********");
            }
            if (sc_input == '1' || sc_input == '2' || sc_input == '#'){
                break;
            }
            while (getchar() != '\n')//跳过输入行剩余部分
                continue;
        }

    }

//    char Time[8];
//    sprintf(Time,"%d",getTime());//获取时间并转换为字符串

    return 0;
}
