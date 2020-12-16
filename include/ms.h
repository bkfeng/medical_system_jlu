
#ifndef MEDICAL_SYSTEM_JLU_MS_H
#define MEDICAL_SYSTEM_JLU_MS_H

/*-------ȫ�ֱ���--------*/
int p_list_length;//������Ϣ���鳤��

//������Ϣ
typedef struct PatientInfo {

    long long ID;       //�Һţ��� �� ʱ �� ���(001-999),11λ

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
    char Rank[20];       //����ҽʦ��������ҽʦ������ҽʦ��סԺҽʦ
    char sex[20];        //�У�Ů
    char Date[10];        //�������ڣ� 0 1 0 1 0 0 1
} DoctorInfo; //ҽ����Ϣ

//ҩƷ��Ϣ
typedef struct Medicine {

    int ID;//  1-50

    char Name[20];//ҩƷ����
    double Unit; //ҩƷ����
} Medicine;

//�����Ϣ
typedef struct CheckUp {

    int ID;//  51-99

    char Name[20];//�������
    double Unit; //��鵥��
} CheckUp;

//������
typedef struct TreatCheck {

    long long ID;//�Һţ��� �� ʱ �� ���(00001-99999)

    int C_ID;//���id
    int Num;//����
    double Total;//�ܼ�
    long long PatientID;
} TreatCheck; //���

//���￪ҩ
typedef struct TreatMed {

    long long ID;//�Һţ��� �� ʱ �� ���(00001-99999)

    int M_ID;//ҩƷid
    int Num; //����
    double Total;
    long long PatientID;//����ID
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


DoctorInfo *readDoctorInfo();//��ȡҽ����Ϣ
Medicine *readMedicine();//��ȡҽ����Ϣ
CheckUp *readCheckUp();//��ȡ�����Ϣ

int getTime();//��ȡ��ǰʱ��
int outpatientSystem();//����ϵͳ
int inhosSystem();//סԺϵͳ
int getNum();//��ȡ����
int addRedRecording(PatientInfo *p);//���ӹҺż�¼
int stringInput(char *d, int lens, int mode);//��ʽ�������ַ���


#endif //MEDICAL_SYSTEM_JLU_MS_H


