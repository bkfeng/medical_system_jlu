
#ifndef MEDICAL_SYSTEM_JLU_MS_H
#define MEDICAL_SYSTEM_JLU_MS_H


//病人信息
typedef struct PatientInfo {

    long long ID;       //挂号:1  月 日 时 分 编号(001-999),11位。例如

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
    char Level[20];       //主任医师、副主任医师、主治医师、住院医师
    char Sex[20];        //男，女
    char Date[10];        //出诊日期： 0 1 0 1 0 0 1
} DoctorInfo; //医生信息

//药品信息
typedef struct Medicine {

    int ID;//

    char Name[20];//药品名称
    double Unit; //药品单价
} Medicine;

//检查信息
typedef struct CheckUp {

    int ID;//

    char Name[20];//检查名称
    double Unit; //检查单价
} CheckUp;

//门诊检查
typedef struct TreatCheck {

    long long ID;//诊疗记录编号；月 日 时 分 编号(00001-99999)

    int C_ID;//检查id
    int Num;//数量
    double Total;//总价
    long long PatientID;
    int Flag;//有效位标志 1有效
} TreatCheck; //检查

//门诊开药
typedef struct TreatMed {

    long long ID;//诊疗记录编号；月 日 时 分 编号(00001-99999)

    int M_ID;//药品id
    int Num; //数量
    double Total;
    long long PatientID;//病人ID
    int Flag;//有效位标志 1有效
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


DoctorInfo *loadDoctorInfo();//获取医生信息
Medicine *loadMedicine();//获取医生信息
CheckUp *loadCheckUp();//获取检查信息

int getTime();//获取当前时间
int getTimeW();//获取星期
int outpatientSystem();//门诊系统
int inhosSystem();//住院系统
int getNum();//获取数字

int countDoctor();//统计出诊情况

int addPatientInfo(PatientInfo *p);//增加挂号记录
int addTreatMedList(TreatMed *p);//增加开药记录
int addTreatCheList(TreatCheck *p);//增加检查记录

int stringInput(char *d, int lens, int mode);//格式化输入字符串

int loadPatientInfo();//导入门诊记录
int loadTreatMedList();//导入开药记录
int loadTreatCheckList();//导入检查记录

int saveTreatMedLIst();//保存开药记录
int saveTreatCheckLIst();//保存检查记录
int savePatientInfo();//保存门诊记录

int queryOS();//查询门诊诊疗记录
int queryTreatPatientInfo();//查询病人诊疗记录
int queryTreatRoom();//查询科室诊疗记录
int queryTreatDoctor();//查询医生诊疗记录
int queryTreatTime();//查询某时段诊疗记录

int modifyTreatList(long long id);//修改删除记录

int importTreatList();//导入诊疗记录

/*--------宏定义---------*/
#define HEAD0 "*****************************************"
#define HEAD1 "-----------------------------------------"

#define HEAD2 "|挂号编号|姓名|年龄|性别|科室|医生|"
#define FORMAT2 "|%-10s|%.2f|\n "

#define HEAD3 "|序号|挂号编号       |名称      |单价   |数量|总价   |"
#define FORMAT3 "|%15lld|%-10s|%7.2f|%4d|%7.2f|\n"
#define DATA3 tr_m_list[j].PatientID,m_list[tr_m_list[j].M_ID].Name,m_list[tr_m_list[j].M_ID].Unit,tr_m_list[j].Num,tr_m_list[j].Total

#define HEAD4 "|序号|挂号编号       |名称      |单价   |数量|总价   |"
#define FORMAT4 "|%15lld|%-10s|%7.2f|%4d|%7.2f|\n"
#define DATA4 tr_c_list[j].PatientID,c_list[tr_c_list[j].C_ID].Name,c_list[tr_c_list[j].C_ID].Unit,tr_c_list[j].Num,tr_c_list[j].Total

#define HEAD5 "|序号|挂号编号       |姓名      |性别|年龄|身份证号          |"
#define FORMAT5 "|%3d.|%15lld|%-10s|%-4s|%-4s|%-18s|\n"
#define DATA5 i,p_list[j].ID,p_list[j].Name,p_list[j].Sex,p_list[j].Age,p_list[j].CardID

#endif //MEDICAL_SYSTEM_JLU_MS_H


