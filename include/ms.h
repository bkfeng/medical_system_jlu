
#ifndef MEDICAL_SYSTEM_JLU_MS_H
#define MEDICAL_SYSTEM_JLU_MS_H


//������Ϣ
typedef struct PatientInfo {

    long long ID;       //�Һ�:1  �� �� ʱ �� ���(001-999),11λ������

    char Name[10];      //����
    char Age[5];        //����
    char Sex[20];       //�У�Ů
    int R_ID;           //����ID
    int D_ID;           //ҽ��ID
    char CardID[20];    //���֤��Ϣ
} PatientInfo; //������Ϣ

//ҽ����Ϣ
typedef struct DoctorInfo {

    int ID;              //����
    int RoomID;          //����Id

    char Name[20];       //����
    char Level[20];       //����ҽʦ��������ҽʦ������ҽʦ��סԺҽʦ
    char Sex[20];        //�У�Ů
    char Date[10];        //�������ڣ� 0 1 0 1 0 0 1
} DoctorInfo; //ҽ����Ϣ

//ҩƷ��Ϣ
typedef struct Medicine {

    int ID;//

    char Name[20];//ҩƷ����
    double Unit; //ҩƷ����
} Medicine;

//�����Ϣ
typedef struct CheckUp {

    int ID;//

    char Name[20];//�������
    double Unit; //��鵥��
} CheckUp;

//������
typedef struct TreatCheck {

    long long ID;//���Ƽ�¼��ţ��� �� ʱ �� ���(00001-99999)

    int C_ID;//���id
    int Num;//����
    double Total;//�ܼ�
    long long PatientID;
    int Flag;//��Чλ��־ 1��Ч
} TreatCheck; //���

//���￪ҩ
typedef struct TreatMed {

    long long ID;//���Ƽ�¼��ţ��� �� ʱ �� ���(00001-99999)

    int M_ID;//ҩƷid
    int Num; //����
    double Total;
    long long PatientID;//����ID
    int Flag;//��Чλ��־ 1��Ч
} TreatMed; //��ҩ


//סԺ��Ϣ
typedef struct TreatInHos {
    char PatientID;
    int InHosDate; //סԺ���ڷֱ�����ʱ��
    int OutHosDate;
    double Deposit; // Ѻ��
} TreatInHos;

//������Ϣ
typedef struct TreatInfo {
    TreatCheck check;
    TreatMed medicine;
    TreatInHos inhos;
} TreatInfo;

//���Ƽ�¼
typedef struct TreatRecord {
    PatientInfo patientinfo;
    DoctorInfo doctorinfo;
    TreatInfo treatinfo;
    struct TreatRecord *next;
} TreatRecord;



/*-----------����-------------*/


DoctorInfo *loadDoctorInfo();//��ȡҽ����Ϣ
Medicine *loadMedicine();//��ȡҽ����Ϣ
CheckUp *loadCheckUp();//��ȡ�����Ϣ

int getTime();//��ȡ��ǰʱ��
int getTimeW();//��ȡ����
int outpatientSystem();//����ϵͳ
int inhosSystem();//סԺϵͳ
int getNum();//��ȡ����

int countDoctor();//ͳ�Ƴ������

int addPatientInfo(PatientInfo *p);//���ӹҺż�¼
int addTreatMedList(TreatMed *p);//���ӿ�ҩ��¼
int addTreatCheList(TreatCheck *p);//���Ӽ���¼

int stringInput(char *d, int lens, int mode);//��ʽ�������ַ���

int loadPatientInfo();//���������¼
int loadTreatMedList();//���뿪ҩ��¼
int loadTreatCheckList();//�������¼

int saveTreatMedLIst();//���濪ҩ��¼
int saveTreatCheckLIst();//�������¼
int savePatientInfo();//���������¼

int queryOS();//��ѯ�������Ƽ�¼
int queryTreatPatientInfo();//��ѯ�������Ƽ�¼
int queryTreatRoom();//��ѯ�������Ƽ�¼
int queryTreatDoctor();//��ѯҽ�����Ƽ�¼
int queryTreatTime();//��ѯĳʱ�����Ƽ�¼

int modifyTreatList(long long id);//�޸�ɾ����¼

int importTreatList();//�������Ƽ�¼

/*--------�궨��---------*/
#define HEAD0 "*****************************************"
#define HEAD1 "-----------------------------------------"

#define HEAD2 "|�Һű��|����|����|�Ա�|����|ҽ��|"
#define FORMAT2 "|%-10s|%.2f|\n "

#define HEAD3 "|���|�Һű��       |����      |����   |����|�ܼ�   |"
#define FORMAT3 "|%15lld|%-10s|%7.2f|%4d|%7.2f|\n"
#define DATA3 tr_m_list[j].PatientID,m_list[tr_m_list[j].M_ID].Name,m_list[tr_m_list[j].M_ID].Unit,tr_m_list[j].Num,tr_m_list[j].Total

#define HEAD4 "|���|�Һű��       |����      |����   |����|�ܼ�   |"
#define FORMAT4 "|%15lld|%-10s|%7.2f|%4d|%7.2f|\n"
#define DATA4 tr_c_list[j].PatientID,c_list[tr_c_list[j].C_ID].Name,c_list[tr_c_list[j].C_ID].Unit,tr_c_list[j].Num,tr_c_list[j].Total

#define HEAD5 "|���|�Һű��       |����      |�Ա�|����|���֤��          |"
#define FORMAT5 "|%3d.|%15lld|%-10s|%-4s|%-4s|%-18s|\n"
#define DATA5 i,p_list[j].ID,p_list[j].Name,p_list[j].Sex,p_list[j].Age,p_list[j].CardID

#endif //MEDICAL_SYSTEM_JLU_MS_H


