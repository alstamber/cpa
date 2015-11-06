#include <stdio.h>
#define STACK_SIZE 256

int stack[STACK_SIZE];
int* sp;

void A(void){
    sp = stack;
}

void B(int val){
    *sp++ = val;
}

int C(void){
    sp--;
    return *sp;
}

void print_stack(char* hint){
    int* p;
    printf("[");
    for (p = stack; p < sp; p++){
        printf("%d", *p);
        if (p < sp - 1) printf(", ");
    }
    printf("] # %s\n", hint);
}

int main(void){
    int i;
    A();
    print_stack("A");
    for (i=1; i<=5; i++){
        B(i);
        print_stack("B");
    }
    for (i=0; i<4; i++){
        int x, y;
        x = C();
        print_stack("C");
        y = C();
        print_stack("C");
        B(x+y);
        print_stack("B");
    }

    return 0;

}
