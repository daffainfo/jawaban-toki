#include <stdio.h>
int main () {
	int i,awal;
	
	scanf("%d",&awal);
	for(i=awal;i>=1;i--) {
		if(awal % i == 0) {
			printf("%d\n",i);
			}
		}
}
