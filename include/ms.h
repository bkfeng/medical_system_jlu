
#ifndef MEDICAL_SYSTEM_JLU_MS_H
#define MEDICAL_SYSTEM_JLU_MS_H

/*----------全局变量-----------*/

//int PatientInfoListLength;//病人信息表长
//int DoctorInfoListLength;//医生信息表长
//int OutPatientListLength;//门诊记录表长



/*-----------函数-------------*/

int getTime();//获取当前时间
int outpatientSystem();//门诊系统
int inhosSystem();//住院系统
unsigned __int64 getNum();//获取数字



/*-----------结构体-----------*/
typedef struct PatientInfo {
    char Name[10];
    int Age;
    long long ID;//挂号；月 日 时 分 科室ID 医生ID 编号
    unsigned __int64 CardID;//身份证信息
} PatientInfo; //患者信息

//医生信息
typedef struct DoctorInfo {
    char Name[10];
    int Rank;
    char sex;
    int ID; //工号
    int RoomID; //科室Id
    int Date; //出诊日期
} DoctorInfo; //医生信息

//检查信息
typedef struct CheckProgram {
    char Name[10];
    double Cost; //药品单价
    int ID;
} CheckProgram;

//药品信息
typedef struct Medicine {
    char Name[10];
    double Cost; //药品单价
    int ID;
} Medicine;

//门诊检查
typedef struct TreatCheck {
    char Name[10];
    double Cost; //检查费用
    long long PatientID;
} TreatCheck; //检查

//门诊开药
typedef struct TreatMed {
    char Name[10];
    double Cost; //药品单价
    int Number; //数量
    int Total;
    long long PatientID;//病人ID
} TreatMed; //开药

//住院信息
typedef struct TreatInHos {
    long long PatientID;
    int InHosDate; //住院日期分别月日时分
    int OutHosDate;
    double Deposit; // 押金
} TreatInHos;

//治疗信息
typedef struct TreatInfo {
    TreatCheck check;
    TreatMed medicine;
    TreatInHos inhos;
} TreatInfo;

//诊疗记录
typedef struct TreatRecord {
    PatientInfo patientinfo;
    DoctorInfo doctorinfo;
    TreatInfo treatinfo;
    struct TreatRecord *next;
} TreatRecord;





#endif //MEDICAL_SYSTEM_JLU_MS_H


