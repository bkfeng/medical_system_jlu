#include "ms.h"
CheckUp *readCheckUp() {
    static CheckUp c_list[30] = {
            {
                "��͸",150,11
            },
            {
                "Ѫ����",60,12
            }
    };
    return c_list;
}