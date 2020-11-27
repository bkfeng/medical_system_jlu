#include <stdio.h>
#include "medical.h"

int main() {
    test test1;
    test1.a = 1;
    printf("Hello, World!\n%d",test1.a);
    test1.b = 1.23;
    printf("%f",test1.b);
    return 0;
}
