#include "ms.h"

CheckUp *loadCheckUp() {

    static CheckUp c_list[30] = {
            {
                    11,"��͸",150
            },
            {
                    12,"Ѫ����",60
            }
    };
    return c_list;
}