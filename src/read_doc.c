#include "ms.h"

DoctorInfo *readDoctorInfo(){

    static DoctorInfo d_list[10] = {
            {
                    "张三","主任医师","男",11,11,0b10101010
            },
            {
                    "李四","主任医师","男",12,12,0b10101011
            }
    };
    return d_list;
}


