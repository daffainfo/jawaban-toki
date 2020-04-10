#include <stdio.h>
int main () {
	int i,k,l,awal;
	
	scanf("%d",&awal);
	for(i=1;i<=awal;i++) {
		for(k=i+1;k<=awal;k++) {
			printf(" ");
		}
		for(l=1;l<=i;l++) {
			printf("*");
		}
		printf("\n");
	}
}
