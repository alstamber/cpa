/* 05D.c */
/* 通貨を使った支払い方法の組み合わせを計算する */
/* メモ化再帰を使用した */


#include <stdio.h>
int s[] = {1000, 500, 100, 50, 10}; //使える通貨
int c[100001][5] = {{0},{0}}; //メモ用の配列

int calc(int amount, int idx){
    if(idx == 4){ //10円玉のみで払う方法は1通りしかない
        return 1;
    }
    if(c[amount][idx] > 0){ //メモ配列に計算結果があればそれを使う(無駄な計算をしない)
        return c[amount][idx];
    }
    int combi = 0;
    int i = 0;
    for(i=0; amount-i*s[idx]>=0; i++){
        combi += calc(amount - i * s[idx], idx + 1); //再帰で組み合わせを計算
    }
    c[amount][idx] = combi; //計算した結果をメモ用配列に記憶
    return combi;
}


int main(){
    int money;

    scanf("%d", &money);

    printf("%d\n", calc(money, 0));

    return 0;
}
