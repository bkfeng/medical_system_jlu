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

/**********
 * 门诊系统
 * @return 1：正确；  0：错误
 */
int outpatientSystem(){

    int os_quit_flag = 0;//门诊系统退出标记
    char time_now[8];//时间字符串

    PatientInfo *p = p_list;
    TreatMed *m = tr_m_list;
    TreatCheck *c = tr_c_list;

    char c_input[100];//字符串输入
    char sc_input;//单个字符输入
    int i_input;

    while (!os_quit_flag){

        system("cls");
        puts("*************欢迎进入门诊系统**************");
        puts("");
        puts("**********请选择需要进行的操作：***********");
        puts("          1---挂号                      ");
        puts("          2---检查                      ");
        puts("          3---开药                      ");
        puts("          4---保存                      ");
        puts("          5---查询                      ");
        puts("          6---导入                      ");
        puts("          7---修改                      ");
        puts("          8---删除                      ");
        puts("          0---返回上层                   ");

        while (1){

            gets(c_input);//获取输入并判断字符串长度
            while (strlen(c_input) > 1){
                puts("*********输入错误，请重新输入**********");
                gets(c_input);
            }

            switch (c_input[0]) {

                case '1':
                    if (addPatientInfo(p)){//增加挂号记录
                        system("pause");//按任意键继续
                    } else{
                        puts("***********输入错误，请重新选择********");
                        system("pause");//按任意键继续
                    }
                    break;
                case '2':
                    if (addTreatCheList(c)){//增加检查记录
                        system("pause");//按任意键继续
                    } else{
                        puts("***********输入错误，请重新选择********");
                        system("pause");//按任意键继续
                    }
                    break;
                case '3':
                    if (addTreatMedList(m)){//增加开药记录
                        system("pause");//按任意键继续
                    } else{
                        puts("***********输入错误，请重新选择********");
                        system("pause");//按任意键继续
                    }
                    break;
                case '4':
                    if (savePatientInfo() && saveTreatMedLIst() && saveTreatCheckLIst()){//保存挂号记录
                        system("pause");//按任意键继续
                    } else{
                        puts("***********输入错误，请重新选择********");
                        system("pause");//按任意键继续
                    }
                    break;
                case '5':
                    if (queryOS()){//查询诊疗记录
                        system("pause");//按任意键继续
                    } else{
                        puts("***********输入错误，请重新选择********");
                        system("pause");//按任意键继续
                    }
                    break;
                case '6':

                    break;

                case '0':
                    os_quit_flag = 1;//退出系统
                    break;
                default:
                    puts("*********输入错误，请重新输入**********");
            }

            if (c_input[0] >= '0'){
                break;
            }
        }

    }

    return 0;
}