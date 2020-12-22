#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ms.h"
extern TreatMed tr_m_list[];
int queryOS() {

    int q_quit_flag = 0;//门诊查询系统退出标记
    char time_now[8];//时间字符串

    char c_input[100];//字符串输入
    char sc_input;//单个字符输入
    int i_input;

    while (!q_quit_flag) {

        system("cls");
        puts("*************欢迎进入门诊查询系统**************");
        puts("");
        puts("**********请选择需要进行的操作：***********");
        puts("          1---查询患者诊疗信息                      ");
        puts("          2---查询科室诊疗记录                     ");
        puts("          3---查询医生诊疗记录                      ");
        puts("          0---返回上层                      ");

        while (1) {

            gets(c_input);//获取输入并判断字符串长度
            while (strlen(c_input) > 1) {
                puts("*********输入错误，请重新输入**********");
                gets(c_input);
            }

            switch (c_input[0]) {

                case '1':
                    if (queryTreatMedPatientInfo(tr_m_list)) {//查询记录
                        system("pause");//按任意键继续
                    } else {
                        puts("***********输入错误，请重新选择********");
                        system("pause");//按任意键继续
                    }
                    break;
                case '2':

                case '3':

                case '4':

                case '0':
                    q_quit_flag = 1;//退出系统
                    break;
                default:
                    puts("*********输入错误，请重新输入**********");
            }

            if (c_input[0] >= '0') {
                break;
            }
        }

    }
    return 1;
}


