#include "ms.h"

CheckUp *loadCheckUp() {

    static CheckUp c_list[30] = {
            {
                    0,"��͸",150
            },
            {
                    1,"Ѫ����",60
            }
    };
    return c_list;
}