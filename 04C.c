#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 7
#define QUEUESIZE 1024*512

typedef struct cost elementtype;

struct cost{
    int x;
    int y;
    int c;
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
    char maze[N][N];
    int i, j, sx, sy, gx, gy;
    struct cost pos;
    struct queue hoge;
    struct cost tsugi;

    for (i=0; i<N; i++){
        fgets(buf, BUFSIZE, stdin);
        for (j=0; j<N && (buf[j] != '\n' && buf[j] != '\0'); j++){
            if(buf[j] == 'S'){
                sx = j;
                sy = i;
                buf[j] = ' ';
            }else if(buf[j] == 'G'){
                gx = j;
                gy = i;
                buf[j] = ' ';
            }
            maze[i][j] = buf[j];
        }
        while(j<N) maze[i][j++] = ' ';
    }

    initqueue(&hoge);

    pos.x = sx;
    pos.y = sy;
    pos.c = 0;

    putq(&hoge, pos);

    while(!queueempty(&hoge)){
        pos = getq(&hoge);
        if (pos.c == N * N){
            pos.c = -1;
            break;
        }
        if (pos.x == gx && pos.y == gy){
            break;
        }
        maze[pos.y][pos.x] = '*';

        if (maze[pos.y][pos.x - 1] == ' ' && 0<= pos.x-1 && 0<=pos.y && pos.y < N){
            tsugi.x = pos.x - 1;
            tsugi.y = pos.y;
            tsugi.c = pos.c + 1;
            putq(&hoge, tsugi);
        }
        if (maze[pos.y][pos.x + 1] == ' ' && pos.x+1 < N && 0<=pos.y && pos.y < N){
            tsugi.x = pos.x + 1;
            tsugi.y = pos.y;
            tsugi.c = pos.c + 1;
            putq(&hoge, tsugi);
        }
        if (maze[pos.y + 1][pos.x] == ' ' && pos.y+1 < N && 0<=pos.x && pos.x < N){
            tsugi.x = pos.x;
            tsugi.y = pos.y + 1;
            tsugi.c = pos.c + 1;
            putq(&hoge, tsugi);
        }
        if(maze[pos.y - 1][pos.x] == ' ' && 0<=pos.y-1 && 0<=pos.x && pos.x < N){
            tsugi.x = pos.x;
            tsugi.y = pos.y - 1;
            tsugi.c = pos.c + 1;
            putq(&hoge, tsugi);
        }

    }

    if (pos.x != gx || pos.y != gy){
        pos.c = -1;
    }



    printf("%d\n", pos.c);

    return 0;


}


