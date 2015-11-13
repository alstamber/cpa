#include <stdio.h>
#include <string.h>
#define STACK_SIZE 80

struct stack{
    char stack[STACK_SIZE];
    int sp;
};

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
    int i;

    fgets(buf, sizeof(buf), stdin);

    init(&kakko);

    for (i=0; buf[i] != '\0';  i++){
        if(buf[i] == '('){
            push(&kakko, ')');
        }
        if(buf[i] == '{'){
            push(&kakko, '}');
        }

        if(buf[i] == ')'){
            if(isempty(&kakko)){
                printf("no\n");
                return 0;
            }
            if(pop(&kakko) != ')'){
                printf("no\n");
                return 0;
            }
        }
        if(buf[i] == '}'){
            if(isempty(&kakko)){
                printf("no\n");
                return 0;
            }
            if(pop(&kakko) != '}'){
                printf("no\n");
                return 0;
            }
        }
    }

    if(!(isempty(&kakko))){
        printf("no\n");
        return 0;
    }

    printf("yes\n");

    return 0;
}


