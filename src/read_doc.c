#include "ms.h"

DoctorInfo *readDoctorInfo(){

    static DoctorInfo d_list[10] = {
            {
                    "����","����ҽʦ","��",11,11,0b10101010
            },
            {
                    "����","����ҽʦ","��",12,12,0b10101011
            }
    };
    return d_list;
}


