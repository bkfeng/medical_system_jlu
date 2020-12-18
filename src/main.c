#include <stdio.h>
#include "ms.h"
#include <stdlib.h>
#include <string.h>
#define HEAD0 "*****************************************"
#define HEAD1 "-----------------------------------------"
#define HEAD2 "|挂号编号|姓名|年龄|性别|科室|医生|"
#define FORMAT "|% "
#define HEAD3 "|名称|单价|数量|总价|"

//全局变量
int g_sum = 0;//医院总营收
int is_save = 0;//是否已经保存

PatientInfo p_h_list[5000];//病人信息历史数组，已保存
int p_h_list_length = 0;//病人信息历史数组长度

PatientInfo p_list[500];//病人信息临时数组，未保存
int p_list_length = 0;//病人信息临时数组长度

int main() {

    int quit_flag = 0;//系统退出标记
    char time_now[8];//时间字符串
    char c_input[100];//字符串输入
    char sc_input;//单个字符输入
    int i_input;

    DoctorInfo *d_list = loadDoctorInfo();//获取医生信息
    Medicine *m_list = loadMedicine();//获取药品信息
    CheckUp *c_list = loadCheckUp();

    loadPatientInfo();

    while (!quit_flag){

        system("cls");
        puts(HEAD0);
        puts("        欢迎进入吉林大学医疗系统         ");
        sprintf(time_now,"%d",getTime());//获取时间并转换为字符串
        puts("");
        printf("         当前系统时间：%s       \n",time_now);
        puts("");
        puts(HEAD1);
        puts("        请选择需要进入的系统：           ");
        puts(HEAD1);
        puts("          1---门诊系统                   ");
        puts("          2---住院系统                   ");
        puts("          #---退出系统                   ");
        puts(HEAD0);


        while (1){

            gets(c_input);//获取输入并判断字符串长度
            while (strlen(c_input) > 1){
                puts("*********输入错误，请重新输入**********");
                gets(c_input);
            }

            switch (c_input[0]) {

                case '1':
                    outpatientSystem();//进入门诊系统
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
            if (c_input[0] == '1' || c_input[0] == '2' || c_input[0] == '#'){
                break;
            }

        }

    }

    return 0;
}
