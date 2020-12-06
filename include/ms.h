
#ifndef MEDICAL_SYSTEM_JLU_MS_H
#define MEDICAL_SYSTEM_JLU_MS_H

/*----------ȫ�ֱ���-----------*/

//int PatientInfoListLength;//������Ϣ��
//int DoctorInfoListLength;//ҽ����Ϣ��
//int OutPatientListLength;//�����¼��

/*-----------�ṹ��-----------*/

//������Ϣ
typedef struct PatientInfo {
    char Name[10];
    char Age[3];
    long long ID;//�Һţ��� �� ʱ �� ����ID ҽ��ID ���
    char CardID[20];//���֤��Ϣ
} PatientInfo; //������Ϣ

//ҽ����Ϣ
typedef struct DoctorInfo {
    char Name[20];
    char Rank[20];//����ҽʦ��������ҽʦ������ҽʦ��סԺҽʦ
    char sex[20];//�У�Ů
    int ID; //����
    int RoomID; //����Id
    int Date; //�������ڣ�8λ�����ƣ���λ1������Ϊ�������ڣ����ڼ����� 1 0 1 0 1 0 0 1
} DoctorInfo; //ҽ����Ϣ

//�����Ϣ
typedef struct CheckUp {
    char Name[20];
    double Cost; //��鵥��
    int ID;
} CheckUp;

//ҩƷ��Ϣ
typedef struct Medicine {
    char Name[20];
    double Cost; //ҩƷ����
    int ID;
} Medicine;

//������
typedef struct TreatCheck {
    char Name[10];
    double Cost; //������
    long long PatientID;
} TreatCheck; //���

//���￪ҩ
typedef struct TreatMed {
    char Name[10];
    double Cost; //ҩƷ����
    int Number; //����
    int Total;
    long long PatientID;//����ID
} TreatMed; //��ҩ

//סԺ��Ϣ
typedef struct TreatInHos {
    long long PatientID;
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


DoctorInfo *readDoctorInfo();//��ȡҽ����Ϣ
Medicine *readMedicine();//��ȡҽ����Ϣ
CheckUp *readCheckUp();//��ȡ�����Ϣ

int getTime();//��ȡ��ǰʱ��
int outpatientSystem();//����ϵͳ
int inhosSystem();//סԺϵͳ
int getNum();//��ȡ����
int addRedRecording(PatientInfo *p);//���ӹҺż�¼


#endif //MEDICAL_SYSTEM_JLU_MS_H


