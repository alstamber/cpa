#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5
#define QUEUESIZE 100

typedef int elementtype;

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


void printq(struct queue* q){
    printf("(");
    if (!queueempty(q)){
        printf("%d", getq(q));
        while (!queueempty(q)) {
            printf(" %d", getq(q));
        }
    }

    printf(")\n");
}

int main(void){
#define BUFSIZE 100
    struct queue qin, qout;
    char buf[BUFSIZE];
    int i, j, x, y;

    initqueue(&qin);
    initqueue(&qout);

    for (i=0; i<N; i++){
        putq(&qin, atoi(fgets(buf, BUFSIZE, stdin)));
    }
    for (i=0; i<N; i++){
        x = getq(&qin);
        for (j=i; j<N-1; j++){
            y = getq(&qin);
            if (x<y) {
                putq(&qin,y);
            } else {
                putq(&qin,x);
                x=y;
            }
        }
        putq(&qout, x);
    }
    printq(&qout);

    return 0;

}



