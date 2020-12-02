/************************
 *      门诊系统
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <ms.h>
#include <stdlib.h>
#include <string.h>

/************************
 *
 * 增加一条挂号记录
 *
 */
int addOSRecording(PatientInfo *p){

    PatientInfo tempP;
    char c_temp[20]="12345";
    puts(c_temp);
    puts("请输入病人姓名：");
    gets(c_temp);
    puts(c_temp);
    printf("请输入病人身份证号：\n");
    strcpy(tempP.Name,c_temp);
    puts("请输入病人年龄：");
    tempP.Age = (int)getNum();
    if (tempP.Age == 0){
        return 0;
    }
    printf("请输入病人身份证号：\n");
    tempP.CardID = getNum();
    if (tempP.CardID == 0){
        return 0;
    }
    printf("请输入挂号科室编号：\n");
    int RID = (int)getNum();
    if (RID == 0){
        return 0;
    }
    printf("请输入挂号医生编号：\n");
    int DID = (int)getNum();
    if (DID == 0){
        return 0;
    }
    tempP.ID = (getTime() * 100 + RID) *100 + DID;
    memcpy(p,&tempP,sizeof(tempP));//临时结构体赋给p指向的数组
    return 1;

}

int outpatientSystem(){

    int os_quit_flag = 0;//门诊系统退出标记
    char time_now[8];//时间字符串

    PatientInfo p_list[500];//病人信息数组
    int p_list_length = 0 ;//病人信息数组长度
    PatientInfo *p = &p_list[p_list_length];

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
        puts("          4---返回上层                   ");

        while (1){

            sc_input = getchar();
            if (sc_input == '\n'){
                continue;
            }
            switch (sc_input) {

                case '1':
                    if (addOSRecording(p)){//增加挂号记录
                        p_list_length++;
                    } else{
                        puts("***********输入错误，请重新选择********");
                    }
                    break;
                case '2':
//                    iSystem();//进入医疗系统
                    break;
                case '3':

                case '#':
                    os_quit_flag = 1;//退出系统
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

    return 0;
}