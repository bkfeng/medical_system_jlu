#include "ms.h"

CheckUp *readCheckUp() {

    static CheckUp c_list[30] = {
            {
                    11,"ÐØÍ¸",150
            },
            {
                    12,"Ñª³£¹æ",60
            }
    };
    return c_list;
}