#include "ms.h"

Medicine *readMedicine(){
    static Medicine m_list[30] = {
            {
                    11,"��Ī����",15
            },
            {
                    12,"�п�",13.5
            }
    };
    return m_list;
}

