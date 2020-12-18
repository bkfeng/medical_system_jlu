#include <stdio.h>
#include "ms.h"


int addTreatmentRecord(TreatMed *p){

    TreatMed tr_temp;
    tr_temp.Flag = 1;

    puts("请输入挂号编号：");
    scanf("%lld",&tr_temp.PatientID);

    puts("请输入药品编号：");
    scanf("%d",&tr_temp.M_ID);

    puts("请输入药品数量：");
    scanf("%d",&tr_temp.Num);

    do {

        puts("请输入药品编号：");
        scanf("%d",&tr_temp.M_ID);

        puts("请输入药品数量：");
        scanf("%d",&tr_temp.Num);

        pi_temp.ID = (long long)getTime() * 1000 + p_list_length + 1;
//    printf("%lld\n",pi_temp.ID);

        //如果上述均正确
        memcpy(p + p_list_length, &pi_temp, sizeof(pi_temp));//临时结构体赋给p指向的数组元素

        puts("***********开药成功********");
        p_list_length++;
//    printf("%lld\n",p->ID);
        puts("该患者是否需要继续开药（1.是/2.否）：");
        if (getNum() == 2){
            return 1;
        }
    } while (i == )
    puts("该患者今日挂号数量已达5个上限。");
}
