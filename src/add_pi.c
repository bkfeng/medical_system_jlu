#include <stdio.h>
#include "ms.h"
#include <string.h>
extern int p_list_length;//病人信息数组长度
//extern int p_list_length_new;//新增病人信息数组长度
extern int is_save;

/*****************
 * 增加一条挂号记录
 * @param p 病人记录数组指针
 * @return 1：正确；  0：错误
 */

int addPatientInfo(PatientInfo *p){

    PatientInfo pi_temp;

    puts("请输入病人姓名：");
    gets(pi_temp.Name);
//    puts(pi_temp.Name);

    puts("请输入病人身份证号：");
    if (!stringInput(pi_temp.CardID,18,1)){
        return 0;
    }

    puts("请输入病人年龄：");
    if (!stringInput(pi_temp.Age,18,1)){
        return 0;
    }

    puts("请输入病人性别：");
    gets(pi_temp.Sex);
//    puts(pi_temp.Sex);

    countDoctor();
    for (int i = 0; i < 5; ++i) {

        puts("请输入挂号科室编号：");
        pi_temp.R_ID = (int)getNum();

        puts("请输入挂号医生编号：");
        pi_temp.D_ID = (int)getNum();

        pi_temp.ID = (long long)getTime() * 1000 + p_list_length + 1;
//    printf("%lld\n",pi_temp.ID);

        //如果上述均正确
        memcpy(p + p_list_length, &pi_temp, sizeof(pi_temp));//临时结构体赋给p指向的数组元素
        printf("挂号编号为：%lld\n",p[p_list_length].ID);
        puts("***********挂号成功********");
        p_list_length++;
        is_save = 0;
        puts("该患者是否需要继续挂号（1.是/2.否）：");
        if (getNum() == 2){
            return 1;
        }
    }
    puts("该患者今日挂号数量已达5个上限。");
    return 1;
}