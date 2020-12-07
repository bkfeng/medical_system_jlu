#include "ms.h"
CheckUp *readCheckUp() {
    static CheckUp c_list[30] = {
            {
                "ÐØÍ¸",150,11
            },
            {
                "Ñª³£¹æ",60,12
            }
    };
    return c_list;
}