#include "ms.h"

DoctorInfo *loadDoctorInfo(){

    static DoctorInfo d_list[10] = {
            {
                    0,11,"张三","主任医师","男","0101010"
            },
            {
                    1,12,"李四","主任医师","男","1010101"
            }
    };
    return d_list;
}


