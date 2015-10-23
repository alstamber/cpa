#define N 10
#include <stdio.h>
#include <stdlib.h>

int comp(const void *c1, const void *c2); //比較関数のプロトタイプ宣言

int main(void){
    int i; //カウンタ
    int a[N]; //N個の要素を持つ配列を確保

    for (i=0;i<N;i++){
        scanf("%d", &a[i]); //N個のデータを読み込む
    }


    qsort(a,N,sizeof(int),comp); //クイックソートする(降順)


    printf("%d\n", a[1]);

    return 0;
}

int comp(const void *ptr1, const void *ptr2){

    if (*(int *)ptr1 > *(int *)ptr2) return -1;
    if (*(int *)ptr1 == *(int *)ptr2) return 0;
    if (*(int *)ptr1 < *(int *)ptr2) return 1;
}


