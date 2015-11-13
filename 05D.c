/* 05D.c */

#include <stdio.h>
int counter(int* kind, int ptr, int value){
    int combi = 0;
    int i = 0;

    if(kind[ptr] == 10){
        combi = 1;
    }else{
        for(i = 0; value - i * kind[ptr] >= 0; i++){
            combi +=counter(kind, ptr-1, value - i * kind[ptr]);
        }
    }
    return combi;
}

int main(){
    int value;
    int kind[] = {10, 50, 100, 500, 1000};
    scanf("%d", &value);

    printf("%d\n", counter(kind, 4, value));

    return 0;

}
