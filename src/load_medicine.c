#include "ms.h"

Medicine *loadMedicine(){
    static Medicine m_list[30] = {
            {
                    0,"��Ī����",15
            },
            {
                    1,"�п�",13.5
            }
    };
    return m_list;
}

