#include <stdio.h>
#include <stdlib.h>
struct stct {int i[100]; char c; double d;};
int gi; char gc; double gd;
int ga[100];
struct stct gs;

int main(){
	int li; char lc; double ld;
	int la[100];
	struct stct ls;
	char *p, *q;
	p = (char *)malloc(100);
	q = (char *)malloc(100);

	printf("%p\n", &gi);
	printf("%p\n", &gc);
	printf("%p\n", &gd);
	printf("%p\n", ga);
	printf("%p\n", &gs);
	printf("%p\n", &li);
	printf("%p\n", &lc);
	printf("%p\n", &ld);
	printf("%p\n", la);
	printf("%p\n", &ls);
	printf("%p\n", p);
	printf("%p\n", q);

	free(p);
	free(q);

	return 0;
}
