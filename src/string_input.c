#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ms.h"

/********
 * 功能：输入字符串并验证
 * @param d 字符串地址
 * @param lens 最大长度
 * @param mode 1：数字  2：字母
 * @return 1：正确 0：错误
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

    strcpy(d,t);//将临时数组内容拷贝到指定地址
    return 1;
}
