#include <stdio.h>
#include "ms.h"
/******************
 * ��ȡ�������벢תΪ����
 *
 * ע�⣺����ֻ�����Ƿ�Ϊ���֣������鳤��
 * @return 1����ȷ 0������
 */
int getNum(){
    char temp[20];
    gets(temp);
    int res = 0;
    //����ַ�ת�������ۼӵ����res
    for (int i = 0; temp[i] != 0; ++i) {
        if (temp[i] >= 48 && temp[i] <= 57){
            res = res * 10 + temp[i] - 48;
        } else{
            return 0;
        }
    }

    return res;
}
