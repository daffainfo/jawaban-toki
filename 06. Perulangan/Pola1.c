#include <stdio.h>
int main () {
	int i,j;
	int n,k;
	
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++) {
		if (i>1) {
			printf(" ");
		}
		if (i % k == 0) {
			printf("*");
			}
		else {
			printf("%d", i);
			}
		}
	printf("\n");
}
