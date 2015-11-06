#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C '.'
#define N 7
#define QUEUESIZE 4*N*N

typedef struct grid elementtype;

struct grid{
    int x, y;
};

struct queue{
    int front, rear;
    elementtype elements[QUEUESIZE];
};

void initqueue(struct queue *q){
    q->front = q->rear = 0;
}

int queueempty(struct queue *q){
    return (q->front==q->rear);
}

void putq(struct queue *q, elementtype x){
    q->elements[q->rear] = x;
    q->rear++;
    if(q->rear >= QUEUESIZE) q->rear=0;
    if(q->rear == q->front){
        printf("queue overflow\n"); exit(1);
    }
}

elementtype getq(struct queue *q){
    elementtype wk;
    if(q->front==q->rear){
        printf("queue underflow\n"); exit(1);
    }
    else{
        wk=q->elements[q->front];
        q->front++;
        if(q->front >= QUEUESIZE) q->front = 0;
        return wk;
    }
}


int main(void){
#define BUFSIZE (N*2)
    char buf[BUFSIZE];
    char canvas[N][N];
    int i, j;
    struct queue hoge;
    struct grid current;
    struct grid next;

    for (i=0; i<N; i++){
        fgets(buf, BUFSIZE, stdin);
        for (j=0; j<N && (buf[j] != '\n' && buf[j] != '\0'); j++){
            canvas[i][j] = buf[j];
        }
        while(j<N){
            canvas[i][j++] = ' ';
        }
    }

    initqueue(&hoge);

    current.x = N / 2;
    current.y = N / 2;


    putq(&hoge, current);

    while(!queueempty(&hoge)){
        current = getq(&hoge);

        canvas[current.y][current.x] = C;
        if(canvas[current.y][current.x - 1] == ' ' && canvas[current.y][current.x - 1] != C && 0<= current.x - 1 && 0<= current.y && current.y < N){
            next.x = current.x - 1;
            next.y = current.y;
            putq(&hoge, next);
        }
        if(canvas[current.y][current.x + 1] == ' ' && canvas[current.y][current.x + 1] != C && current.x + 1 < N && 0<= current.y && current.y < N){
            next.x = current.x + 1;
            next.y = current.y;
            putq(&hoge, next);
        }
        if(canvas[current.y - 1][current.x] == ' ' && canvas[current.y - 1][current.x] != C && 0<= current.x && current.x < N && 0<= current.y - 1){
            next.x = current.x;
            next.y = current.y - 1;
            putq(&hoge, next);
        }
        if(canvas[current.y + 1][current.x] == ' ' && canvas[current.y + 1][current.x] != C && 0<= current.x && current.x < N && current.y + 1 < N){
            next.x = current.x;
            next.y = current.y + 1;
            putq(&hoge, next);
        }

    }



    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }


    return 0;


}


