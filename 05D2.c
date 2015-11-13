#include <stdio.h>
int table[2000];
int shurui[] = {10, 50, 100, 500, 1000};

int function(int ptr,int amount){
    int i;
    int comb = 0;
    if(table[amount] != 0){
        return table[amount];
    }else if (ptr == 0){
        return 1;
    }else{
        for(i=0;amount-i*shurui[ptr]>=0;i++){
            comb += function(ptr-1, amount - i * shurui[ptr]);
        }
    }

    table[amount] = comb;
    printf("%d\n", comb);
    return comb;
}


int main(){
    int kingaku;
    int i;
    for(i=0;i<2000;i++){
        table[i] = 0;
    }
    scanf("%d", &kingaku);
    printf("%d\n", function(4, kingaku));

    return 0;

}


