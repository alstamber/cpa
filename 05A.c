/* 05A.c */
/* 整数の合計 */
#include <stdio.h>

int sum(int n, int m);

int sum(int n, int m){
    if (n <= m){
        return n + sum(n + 1, m);
    }
    return 0;
}

int main(){

    int num1, num2;
    int result;

    scanf("%d%d", &num1, &num2);

    result = sum(num1, num2);

    printf("%d\n", result);

    return 0;
}
