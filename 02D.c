#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4
#define BUFLEN 100

float m_a[N][N]; //冪乗の結果を保持する配列
float m_b[N][N]; //もともとの行列を保持する配列
float m_c[N][N]; //計算の途中結果を保持するバッファ配列
char buf[BUFLEN];

int main(void){
	int r,c; //行および列のカウンタ
	int i,j; //for文用カウンタ

	//読み込み
	for(r=0; r<N; r++){
		char* p = fgets(buf, sizeof(buf), stdin);
		for(c=0; c<N; c++){
			m_a[r][c] = strtof(p, &p); //文字列をfloat型へ
			m_b[r][c] = m_a[r][c];
		}
	}

	for(i=0;i<M-1; i++){ //乗算を繰り返す(e.g. 4乗なら3回繰り返す)
		for(r=0; r<N; r++){
			for(c=0; c<N; c++){
				for(j=0; j<N; j++){
					m_c[r][c] += m_b[r][j] * m_a[j][c];
				}
			}
		}
		for(r=0; r<N; r++){
			for(c=0; c<N; c++){
				m_a[r][c] = m_c[r][c]; //バッファから結果を移す
				m_c[r][c] = 0.0; //バッファをクリア
			}
		}
	}

	//出力
	for(r=0; r<N; r++){
		for(c=0; c<N; c++){
			if (c>0) printf(" ");
			printf("%f", m_a[r][c]);
		}
		printf("\n");
	}

	return 0;

}



