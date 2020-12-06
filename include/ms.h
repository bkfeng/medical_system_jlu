
#ifndef MEDICAL_SYSTEM_JLU_MS_H
#define MEDICAL_SYSTEM_JLU_MS_H

/*----------全局变量-----------*/

//int PatientInfoListLength;//病人信息表长
//int DoctorInfoListLength;//医生信息表长
//int OutPatientListLength;//门诊记录表长

/*-----------结构体-----------*/

//病人信息
typedef struct PatientInfo {
    char Name[10];
    char Age[3];
    long long ID;//挂号；月 日 时 分 科室ID 医生ID 编号
    char CardID[20];//身份证信息
} PatientInfo; //患者信息

//医生信息
typedef struct DoctorInfo {
    char Name[20];
    char Rank[20];//主任医师、副主任医师、主治医师、住院医师
    char sex[20];//男，女
    int ID; //工号
    int RoomID; //科室Id
    int Date; //出诊日期：8位二进制，首位1，其余为出诊日期（星期几）； 1 0 1 0 1 0 0 1
} DoctorInfo; //医生信息

//检查信息
typedef struct CheckUp {
    char Name[20];
    double Cost; //检查单价
    int ID;
} CheckUp;

//药品信息
typedef struct Medicine {
    char Name[20];
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


/*-----------函数-------------*/


DoctorInfo *readDoctorInfo();//获取医生信息
Medicine *readMedicine();//获取医生信息
CheckUp *readCheckUp();//获取检查信息

int getTime();//获取当前时间
int outpatientSystem();//门诊系统
int inhosSystem();//住院系统
int getNum();//获取数字
int addRedRecording(PatientInfo *p);//增加挂号记录


#endif //MEDICAL_SYSTEM_JLU_MS_H


