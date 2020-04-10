#include <stdio.h>
int main () {
	int i, awal, bil;
	int error;
	
	scanf("%d",&awal);
	for(i=1;i<=awal;i++) {
		
		if(i==42) {
			printf("ERROR\n");
			break;
			}
		if(i%10 == 0 ) {
			continue;
			}
		printf("%d\n",i);
	}
	
}
