
#ifndef MEDICAL_SYSTEM_JLU_MS_H
#define MEDICAL_SYSTEM_JLU_MS_H

/*-------全局变量--------*/
int p_list_length;//病人信息数组长度

//病人信息
typedef struct PatientInfo {

    long long ID;       //挂号；月 日 时 分 编号(001-999),11位

    char Name[10];      //姓名
    char Age[5];        //年龄
    char Sex[20];       //男，女
    int R_ID;           //科室ID
    int D_ID;           //医生ID
    char CardID[20];    //身份证信息
} PatientInfo; //患者信息

//医生信息
typedef struct DoctorInfo {

    int ID;              //工号
    int RoomID;          //科室Id

    char Name[20];       //姓名
    char Rank[20];       //主任医师、副主任医师、主治医师、住院医师
    char sex[20];        //男，女
    char Date[10];        //出诊日期： 0 1 0 1 0 0 1
} DoctorInfo; //医生信息

//药品信息
typedef struct Medicine {

    int ID;//  1-50

    char Name[20];//药品名称
    double Unit; //药品单价
} Medicine;

//检查信息
typedef struct CheckUp {

    int ID;//  51-99

    char Name[20];//检查名称
    double Unit; //检查单价
} CheckUp;

//门诊检查
typedef struct TreatCheck {

    long long ID;//挂号；月 日 时 分 编号(00001-99999)

    int C_ID;//检查id
    int Num;//数量
    double Total;//总价
    long long PatientID;
} TreatCheck; //检查

//门诊开药
typedef struct TreatMed {

    long long ID;//挂号；月 日 时 分 编号(00001-99999)

    int M_ID;//药品id
    int Num; //数量
    double Total;
    long long PatientID;//病人ID
} TreatMed; //开药




//住院信息
typedef struct TreatInHos {
    char PatientID;
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
int stringInput(char *d, int lens, int mode);//格式化输入字符串


#endif //MEDICAL_SYSTEM_JLU_MS_H


