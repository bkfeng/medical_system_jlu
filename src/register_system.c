/************************
 *
 * 增加一条挂号记录
 *
 */
#include <stdio.h>
#include "ms.h"
#include <string.h>

int addRedRecording(PatientInfo *p){

    PatientInfo temp_pi;

    puts("请输入病人姓名：");
    gets(temp_pi.Name);
    puts(temp_pi.Name);

    printf("请输入病人身份证号：\n");
    gets(temp_pi.CardID);
    puts(temp_pi.CardID);

    puts("请输入病人年龄：");
    gets(temp_pi.Age);
    puts(temp_pi.Age);

    puts("请输入病人性别：");
    gets(temp_pi.Sex);
    puts(temp_pi.Sex);

    for (int i = 0; i < 5; ++i) {

        puts("请输入挂号科室编号：");
        temp_pi.R_ID = (int)getNum();

        puts("请输入挂号医生编号：");
        temp_pi.D_ID = (int)getNum();

        temp_pi.ID = (long long)getTime() * 1000 + p_list_length + 1;
//    printf("%lld\n",temp_pi.ID);

        //如果上述均正确
        memcpy(p + p_list_length,&temp_pi,sizeof(temp_pi));//临时结构体赋给p指向的数组元素
        printf("挂号编号为：%lld\n",p[p_list_length].ID);
        puts("***********挂号成功********");
        p_list_length++;
//    printf("%lld\n",p->ID);
        puts("该患者是否需要继续挂号（1.是/2.否）：");
        if (getNum() == 2){
            return 1;
        }
    }
    puts("该患者今日挂号数量已达5个上限。");
    return 1;
}