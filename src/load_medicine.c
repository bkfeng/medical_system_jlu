#include "ms.h"

Medicine *loadMedicine(){
    static Medicine m_list[30] = {
            {
                    0,"°¢ÄªÎ÷ÁÖ",15
            },
            {
                    1,"¸Ğ¿µ",13.5
            }
    };
    return m_list;
}

