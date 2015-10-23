#include <stdio.h>
#include <string.h>
#define MAXLEN 78 //最大長

char buf[MAXLEN+2]; //文字列を格納する配列
char max[MAXLEN+2]; //最大長文字列を格納する配列

int main(void){
    int maxlen = 0; //最大長文字列の長さを保持する変数
    while (1){
        int len; //文字列の長さを保持する変数
        int cmp; //strcmpの返り値を保持する変数
        int i;
        fgets(buf,sizeof(buf),stdin); //一行読む
        if(buf[0] == '\n' || buf[0] == '\0'){ break; } //空行で終了

        len = strlen(buf);

        if (buf[len-1] == '\n'){ //行末の改行は消去
            buf[len-1] == '\0';
        }

        for(i=0;i<len;i++){ //#以降は消去
            if (buf[i] == '#'){
                buf[i] = '\0';
                break;
            }
        }

        len = strlen(buf);

        if (maxlen < len){//より長い文字列が見つかった
            maxlen = len;
            strcpy(max,buf);
        }else if (maxlen == len){//暫定最大長の文字列とおなじ長さの文字列が見つかった
            cmp = strcmp(max,buf);//辞書順で比較
            if (cmp > 0){
                strcpy(max,buf);
            }
        }
    }

    printf("%s\n", max);//最大長の文字列を表示

    return 0;

}



