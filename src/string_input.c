#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ms.h"

/********
 * ���ܣ������ַ�������֤
 * @param d �ַ�����ַ
 * @param lens ��󳤶�
 * @param mode 1������  2����ĸ
 * @return 1����ȷ 0������
 */
int stringInput(char *d, int lens, int mode) {

    char t[255];
    gets(t);
    if (strlen(t) > lens) {
        return 0;
    }
    if (mode == 2) {

        for (int i = 0; t[i] != 0; ++i) {
            if (!isalpha(t[i])) {
                return 0;
            }
        }
    }

    if (mode == 1) {

        for (int i = 0; t[i] != 0; ++i) {
            if (!isdigit(t[i])) {
                return 0;
            }
        }
    }

    strcpy(d,t);//����ʱ�������ݿ�����ָ����ַ
    return 1;
}
