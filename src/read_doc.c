#include "ms.h"

DoctorInfo *readDoctorInfo(){

    static DoctorInfo d_list[10] = {
            {
                    11,11,"张三","主任医师","男","0101010"
            },
            {
                    12,12,"李四","主任医师","男","1010101"
            }
    };
    return d_list;
}


