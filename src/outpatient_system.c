#include <ctype.h>
#include <stdio.h>
#include <ms.h>
extern PatientInfo list[];

void AddOSRecording(){

    puts("请输入病人姓名：");
    gets(list[PatientInfoListLength].Name);
    printf("请输入病人年龄：\n");
    scanf("%d",&list[PatientInfoListLength].Age);
    printf("请输入病人身份证号：\n");
    scanf("%d",&list[PatientInfoListLength].CardID);
    printf("请输入挂号科室编号：\n");
    int RID;
    scanf("%d",&RID);
    int DID;
    printf("请输入挂号医生编号：\n");
    scanf("%d",&DID);
    list[PatientInfoListLength].ID =

}