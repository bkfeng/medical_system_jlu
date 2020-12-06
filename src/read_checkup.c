#include "ms.h"
CheckUp *readCheckUp() {
    static CheckUp c_list[30] = {
            {
                "胸透",150,11
            },
            {
                "血常规",60,12
            }
    };
    return c_list;
}