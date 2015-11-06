#include <stdio.h>
#include <string.h>

struct student {
    int id;
    char account[9];
};

void set (struct student* s, int id, char* account){
    s->id = id; //学籍番号を設定
    strcpy(s->account, account); //アカウント名を設定
}

struct student* search (struct student students[], int n, int id){
    int i;

    for(i=0; i<n; i++){
        if(students[i].id == id){
            return &students[i]; //見つかったら対応する構造体のアドレスを返す
        }
    }

    return NULL; //最後までみつからなかったらヌルポインタを返す

}

int main(){
#define BUFSIZE 80
    struct student students[5], *s;
    char buf[BUFSIZE], *account;
    int i, len, id;

// studentsに学籍番号とアカウント名を設定

    for (i=0; i<5; i++){
        fgets(buf, sizeof(buf), stdin);
        len = strlen(buf);
        if(buf[len - 1] == '\n'){
            buf[len - 1] = '\0';
        }
        buf[7] = '\0';
        id = atoi(buf);
        account = buf + 8;
        while (*account == ' '){account++;}
        set(&students[i], id, account);
    }

// 学籍番号を入力させ、検索してきて表示する

    while (fgets(buf, sizeof(buf), stdin)){
        if (buf[0] == '\n' || buf[0] == '\0'){
            break;
        }
        s = search(students, 5, atoi(buf));
        if (s == NULL){
            printf("no data\n");
        }else{
            printf("%s\n", s->account);
        }
    }

    return 0;
}


