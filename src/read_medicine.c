#include "ms.h"

Medicine *readMedicine(){
    static Medicine m_list[30] = {
            {
                "°¢ÄªÎ÷ÁÖ",15,11
            },
            {
                "¸Ğ¿µ",13.5,12
            }
    };
    return m_list;
}

