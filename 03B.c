#include <stdio.h>
#include <string.h>
#define LEN 79

char* find(char* s1, char* s2){
    int i,j; //Counter
    i = 0;
    j = 0;
    char *tmp, *s2_head; //tmpは返り値となるアドレスを保持するポインタ、s2_headはs2の先頭アドレスを保持

    s2_head = s2; //先頭アドレスを保持
    tmp = NULL; //tmpを取り合えず初期化

    while(!((*s1=='\0') || (*s2=='\0'))){ //s1, s2が終端に達するまで
       if(*s1 != *s2){ //文字を比較して異なっていたとき
          s1++; //1文字進める
          s2 = s2_head; //s2を先頭に戻す
          tmp = NULL; //tmpを初期化
       }else{ //文字を比較して同じだったとき
           if(tmp == NULL){
            tmp = s1; //この時のs1のアドレスが返り値の候補となるので、tmpに保持
           }
          s1++; //一文字ずつ進める
          s2++;
       }

    }

    return tmp;
}

int main(){
    char str1[LEN], str2[LEN];
    char* result; //結果を保持するポインタ

    scanf("%s", str1);
    scanf("%s", str2);

    result = find(str1, str2);

    if(result == NULL){ //結果がヌルポインタなら
        printf("\n"); //空行を出力
    }else{
        printf("%s\n", result);
    }

    return 0;
}


