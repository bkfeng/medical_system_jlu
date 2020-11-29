#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//病人信息
typedef struct PatientInfo{

    char Name[10];
    int Age;
    long long ID;//挂号；月 日 时 分 科室ID 医生ID 编号
    int CardID;//身份证信息

}PatientInfo; //患者信息


//医生信息
typedef struct DoctorInfo{

    char Name[10];
    int Rank;
    int ID; //工号
    int RoomID; //科室Id
    int Date; //出诊日期

}DoctorInfo; //医生信息



//检查信息
typedef struct CheckProgagm{

    char Name[10];
    double Cost; //药品单价
    int ID;

}CheckProgram;//检查信息


//药品信息
typedef struct Medicine{

    char Name[10];
    double Cost; //药品单价
    int ID;

}Medicine;



//门诊检查
typedef struct TreatCheck{

    char Name[10];
    double Cost; //检查费用
    long long PatientID;

}TreatCheck; //检查



//门诊开药
typedef struct TreatMed{

    char Name[10];
    double Cost; //药品单价
    int Number; //数量
    int Total;
    long long PatientID;//病人ID

}TreatMed; //开药



//住院信息
typedef struct TreatInHos{

    long long PatientID;
    int InHosDate; //住院日期分别月日时分
    int OutHosDate;
    double Deposit; // 押金

}TreatInHos;


//治疗信息
typedef struct TreatInfo{

    TreatCheck check;
    TreatMed medicine;
    TreatInHos inhos;


}TreatInfo;

 //诊疗记录
typedef struct TreatRecord{

    PatientInfo patientinfo;
    DoctorInfo doctorinfo;
    TreatInfo treatinfo;
    struct TreatRecord *next;

}TreatRecord;





int main()
{
    double HospitalFund = 0;

    time_t timep;

struct tm *p;

time (&timep);

p=gmtime(&timep);


printf("%d\n",p->tm_min); /*获取当前分*/

printf("%d\n",8+p->tm_hour);/*获取当前时,这里获取西方的时间du,刚好相差八个小时zhi*/

printf("%d\n",p->tm_mday);/*获取当前月份日数,范围是1-31*/

printf("%d\n",1+p->tm_mon);/*获取当前月份,范围是0-11,所以要加1*/









    return 0;
}
