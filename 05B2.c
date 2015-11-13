/* 05B.c */
/* 括弧の対応をスタックで判定する */

#include <stdio.h>
#include <string.h>
#define STACK_SIZE 80

/* 括弧をpushするstack */
struct stack{
    char stack[STACK_SIZE];
    int sp;
};

/* stackを操作するための関数群 */
void init(struct stack* st){
    st->sp = 0;
}

int isempty(struct stack* st){
    return (st->sp == 0);
}

void push(struct stack* st, char c){
    if (st->sp == STACK_SIZE){
        printf("stack overflow\n");
        return;
    }
    st->stack[st->sp] = c;
    st->sp++;
}

char pop(struct stack* st){
    if (st->sp == 0){
        printf("stack underflow\n");
        return 1;
    }
    st->sp--;
    return st->stack[st->sp];
}



int main(){
#define BUFSIZE 80
    char buf[BUFSIZE];
    struct stack kakko;
    char tmp;
    int i;

    fgets(buf, sizeof(buf), stdin); //文字列を標準入力から取得

    init(&kakko); //stackを初期化

    for (i=0; buf[i] != '\0';  i++){
        tmp = buf[i];

        switch(tmp){
            case '(': //"("を見つけたら")"をstackにpush
                push(&kakko, ')');
                break;
            case '{': //"{"を見つけたら"}"をstackにpush
                push(&kakko, '}');
                break;

            case ')': //")"か"}"を見つけたら
            case '}':
                if(isempty(&kakko)){ //閉じ括弧を見つけた段階でstackが空と言うことは開き括弧が出てくる前に閉じ括弧が現れたということ
                    printf("no\n");
                    return 0;
                }
                if(pop(&kakko) != tmp){ //stackの中身と一致しないということは期待する種類とは違う括弧だったということ
                    printf("no\n");
                    return 0;
                }
        }
    }

    if(!(isempty(&kakko))){ //すべて終わったあとでもstackに残っているということは閉じ括弧が足りないということ
        printf("no\n");
        return 0;
    }

    printf("yes\n");

    return 0;
}


