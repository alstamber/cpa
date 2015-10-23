#include <stdio.h>

int main(void){
    int n,m,tmp;
    int a[2];
    int i;

    for (i=0;i<=1;i++){
        scanf("%d", &a[i]); //数を読み込む
    }

    if (a[0] >= a[1]){ //n<=mとなるように並び替える
        m = a[0];
        n = a[1];
    }else{
        n = a[0];
        m = a[1];
    }

    while (n != 0){ //ユークリッドの互除法適用
        tmp = m;
        m = n;
        n = tmp % n;
    }

    printf("%d\n", m); //結果表示

    return 0;
}


