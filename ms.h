#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//������Ϣ
typedef struct PatientInfo{

    char Name[10];
    int Age;
    long long ID;//�Һţ��� �� ʱ �� ����ID ҽ��ID ���
    int CardID;//���֤��Ϣ

}PatientInfo; //������Ϣ


//ҽ����Ϣ
typedef struct DoctorInfo{

    char Name[10];
    int Rank;
    int ID; //����
    int RoomID; //����Id
    int Date; //��������

}DoctorInfo; //ҽ����Ϣ



//�����Ϣ
typedef struct CheckProgagm{

    char Name[10];
    double Cost; //ҩƷ����
    int ID;

}CheckProgram;//�����Ϣ


//ҩƷ��Ϣ
typedef struct Medicine{

    char Name[10];
    double Cost; //ҩƷ����
    int ID;

}Medicine;



//������
typedef struct TreatCheck{

    char Name[10];
    double Cost; //������
    long long PatientID;

}TreatCheck; //���



//���￪ҩ
typedef struct TreatMed{

    char Name[10];
    double Cost; //ҩƷ����
    int Number; //����
    int Total;
    long long PatientID;//����ID

}TreatMed; //��ҩ



//סԺ��Ϣ
typedef struct TreatInHos{

    long long PatientID;
    int InHosDate; //סԺ���ڷֱ�����ʱ��
    int OutHosDate;
    double Deposit; // Ѻ��

}TreatInHos;


//������Ϣ
typedef struct TreatInfo{

    TreatCheck check;
    TreatMed medicine;
    TreatInHos inhos;


}TreatInfo;

 //���Ƽ�¼
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


printf("%d\n",p->tm_min); /*��ȡ��ǰ��*/

printf("%d\n",8+p->tm_hour);/*��ȡ��ǰʱ,�����ȡ������ʱ��du,�պ����˸�Сʱzhi*/

printf("%d\n",p->tm_mday);/*��ȡ��ǰ�·�����,��Χ��1-31*/

printf("%d\n",1+p->tm_mon);/*��ȡ��ǰ�·�,��Χ��0-11,����Ҫ��1*/









    return 0;
}
