#include <stdio.h>
#include "ms.h"
#include <stdlib.h>
#include <string.h>

//全局变量
double g_sum = 0;//医院总营收
int is_save = 1;//是否已经保存。1--已保存，0--未保存

PatientInfo p_list[5000];//挂号记录
int p_list_length = 0;//病人信息历史数组长度
//int p_list_length_new = 0;//新增病人信息历史数组长度

TreatMed tr_m_list[5000];//诊疗记录  开药
int tr_m_list_length = 0;//诊疗记录长度
//int tr_m_list_length_new = 0;//新增诊疗记录长度

TreatCheck tr_c_list[5000];//诊疗记录  检查
int tr_c_list_length = 0;//诊疗记录长度
//int tr_c_list_length_new = 0;//新增诊疗记录长度

Medicine m_list[30] = {
        {
                0,"阿莫西林",15
        },
        {
                1,"感康",13.5
        },
        {
                2,"布洛芬",5.6
        },
        {
                3,"风油精",4.5
        },
        {
                4,"创可贴",1
        },
        {
                5,"双氧水",2
        }
};

CheckUp c_list[30] = {
        {
                0,"胸透",150
        },
        {
                1,"血常规",60
        },
        {
                2,"心电图",100
        },
        {
                3,"B超",80
        },
        {
                4,"胃镜",300
        },
        {
                5,"磁共振",850
        }
};

DoctorInfo d_list[10] = {
        {
                0,11,"张三","主任医师","男","0101010"
        },
        {
                1,11,"李四","主治医师","男","1010101"
        },
        {
                2,11,"王五","住院医师","男","0101010"
        },
        {
                3,12,"张红","主任医师","女","1010101"
        },
        {
                4,12,"刘洋","主治医师","男","0101010"
        },
        {
                5,12,"李华","住院医师","男","1010101"
        }
};

int main() {

    int quit_flag = 0;//系统退出标记
    char time_now[8];//时间字符串
    char c_input[100];//字符串输入

//    DoctorInfo *d_list = loadDoctorInfo();//获取医生信息
//    m_list = loadMedicine();//获取药品信息
//    CheckUp *c_list = loadCheckUp();

    /*----导入历史记录----*/
    loadPatientInfo();
    loadTreatMedList();
    loadTreatCheckList();
    system("pause");//按任意键继续

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
//
                    break;
                case '#':
                    if (is_save){
                        quit_flag = 1;//退出系统
                    } else{
                        puts("记录未保存，是否退出（1.保存并退出；2.直接退出）：");
                        gets(c_input);//获取输入并判断字符串长度
                        while (strlen(c_input) > 1){
                            puts("*********输入错误，请重新输入**********");
                            gets(c_input);
                        }
                        if (c_input[0] == 1){
                            if (savePatientInfo() && saveTreatMedLIst() && saveTreatCheckLIst()){
                                quit_flag = 1;
                            } else{
                                puts("保存失败！");
                                system("pause");
                            }
                        } else{
                            quit_flag = 1;
                        }
                    }
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
