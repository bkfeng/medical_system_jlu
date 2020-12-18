#include "ms.h"

Medicine *loadMedicine(){
    static Medicine m_list[30] = {
            {
                    11,"°¢ÄªÎ÷ÁÖ",15
            },
            {
                    12,"¸Ğ¿µ",13.5
            }
    };
    return m_list;
}

