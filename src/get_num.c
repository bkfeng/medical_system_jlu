/*************
 *
 * 获取键盘输入并转为数字
 *
 * 注意：函数只检验是否为数字，不检验长度
 */

#include <stdio.h>
#include <ms.h>
unsigned __int64 getNum(){
    char temp[20];
    gets(temp);
    unsigned __int64 res = 0;
    //逐个字符转换，并累加到结果res
    for (int i = 0; i < 20; ++i) {
        if (temp[i] >= 48 && temp[i] <= 57){
            res = res * 10 + temp[i] - 48;
        } else{
            return 0;
        }
    }

    return res;
}
