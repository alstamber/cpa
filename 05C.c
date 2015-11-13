/* 05C.c */
/* 括弧の対応を再帰で調べる */

#include <stdio.h>
#include <string.h>

char* check(int* c, char* s){
    char* tmp;
    while(*s != '\0'){
        if(*s == ')' || *s == '}'){ //閉じ括弧なら
            *c = 2; //とりあえず分類は2にしておく
            return s; //そこのアドレスを返す
        }
        if(*s == '(' || *s == '{'){ //開き括弧なら
            tmp = check(c, s+1); //括弧の次の位置を引数として再帰的にcheckを呼び出す
            if(*c == 3){
                return tmp; //分類が3なら直ちにreturn
            }
            if((*s == '(' && *tmp == ')')||(*s == '{' && *tmp == '}')){ //括弧が対応していれば
                s = tmp+1; //閉じ括弧の次の位置へ調べる位置を移動
                continue;
            }else{
                *c = 3; //対応していないようなら分類を3にする
                return tmp; //その位置のアドレスを返す
            }
        }
        s++;
    }
    *c = 1; //ここまでこれるのは完全に括弧の対応がとれている時だけであるので、ここで改めて分類を1に設定
    return s;
}

int main(){
#define BUFSIZE 80
    char buf[BUFSIZE];
    int bunrui = 1;

    fgets(buf, sizeof(buf), stdin);

    check(&bunrui, buf);

    if(bunrui == 1){
        printf("yes\n"); //分類が1ならOK
    }else{
        printf("no\n"); //1以外なら対応がとれていない
    }

    return 0;
}


