#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    int id;
    char account[9];
};

void set (struct student* s, int id, char* account){
    s->id = id;
    strcpy(s->account, account);
}

struct student* search (struct student students[], int n, int id){
    int i;

    for(i=0; i<n; i++){
        if(students[i].id == id){
            return &students[i]; //見つかったら対応する構造体のアドレスを返す
        }
    }

    return NULL; //みつからなかったらヌルポインタを返す

}


int main(){
#define BUFSIZE 80
    struct student *s, *tmp_ptr;
    struct student* students; //動的に確保された構造体配列を扱う時に使うポインタ
    int student_len = 1; //構造体配列の大きさ
    students = (struct student *)malloc(sizeof(struct student) * student_len); //mallocでとりあえず1人分の構造体を確保
    char buf[BUFSIZE], *account;
    int i, len, id;
    i = 0;

    while(fgets(buf, sizeof(buf), stdin)){
        if(((buf[0] == '\n') || (buf[0] == '\0'))){ //空行が入力されたらbreak
            break;
        }
        len = strlen(buf);
        if(buf[len - 1] == '\n'){
            buf[len - 1] = '\0';
        }
        buf[7] = '\0';
        id = atoi(buf);
        account = buf + 8;
        while (*account == ' '){account++;}
        set(&students[i], id, account);
        i++;
        if(i == student_len){ //構造体配列があふれそうになったら
            student_len = student_len * 2;
            tmp_ptr = (struct student *)realloc(students, sizeof(struct student) * student_len); //2倍の大きさにして確保
            if (tmp_ptr == NULL){ //reallocに失敗したら
                exit(1); //強制終了
            }else{
                students = tmp_ptr;
            }
        }
    }

    while (fgets(buf, sizeof(buf), stdin)){
        if (buf[0] == '\n' || buf[0] == '\0'){
            break;
        }
        s = search(students, student_len, atoi(buf));
        if (s == NULL){
            printf("no data\n");
        }else{
            printf("%s\n", s->account);
        }
    }

    return 0;
}


