
#ifndef MEDICAL_SYSTEM_JLU_MS_H
#define MEDICAL_SYSTEM_JLU_MS_H

/*----------ȫ�ֱ���-----------*/

//int PatientInfoListLength;//������Ϣ��
//int DoctorInfoListLength;//ҽ����Ϣ��
//int OutPatientListLength;//�����¼��



/*-----------����-------------*/

int getTime();//��ȡ��ǰʱ��
int outpatientSystem();//����ϵͳ
int inhosSystem();//סԺϵͳ
unsigned __int64 getNum();//��ȡ����



/*-----------�ṹ��-----------*/
typedef struct PatientInfo {
    char Name[10];
    int Age;
    long long ID;//�Һţ��� �� ʱ �� ����ID ҽ��ID ���
    unsigned __int64 CardID;//���֤��Ϣ
} PatientInfo; //������Ϣ

//ҽ����Ϣ
typedef struct DoctorInfo {
    char Name[10];
    int Rank;
    char sex;
    int ID; //����
    int RoomID; //����Id
    int Date; //��������
} DoctorInfo; //ҽ����Ϣ

//�����Ϣ
typedef struct CheckProgram {
    char Name[10];
    double Cost; //ҩƷ����
    int ID;
} CheckProgram;

//ҩƷ��Ϣ
typedef struct Medicine {
    char Name[10];
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





#endif //MEDICAL_SYSTEM_JLU_MS_H


