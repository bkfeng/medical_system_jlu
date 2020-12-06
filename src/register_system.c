
#include <stdio.h>
#include "ms.h"
#include <string.h>

/************************
 *
 * 增加一条挂号记录
 *
 */
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

    printf("请输入挂号科室编号：\n");
    int RID =getNum();
    printf("%d",RID);
    if (RID == 0){
        return 0;
    }

    printf("请输入挂号医生编号：\n");
    int DID = (int)getNum();
    if (DID == 0){
        return 0;
    }
    temp_pi.ID = (getTime() * 100 + RID) *100 + DID;
    printf("%I64d",temp_pi.ID);
    memcpy(p,&temp_pi,sizeof(temp_pi));//临时结构体赋给p指向的数组
    return 1;
}