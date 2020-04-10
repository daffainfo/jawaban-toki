#include <stdio.h>
int main () {
	int i,k,awal,x=0;
	
	scanf("%d",&awal);
	for(i=1;i<=awal;i++) {
		for(k=0;k<i;k++) {
			printf("%d",x);
			x=x+1;
			if(x==10) {
				x=0;
			}
		}
		printf("\n");
	}
	return 0;
}
