#include "ms.h"

Medicine *readMedicine(){
    static Medicine m_list[30] = {
            {
                "��Ī����",15,11
            },
            {
                "�п�",13.5,12
            }
    };
    return m_list;
}

