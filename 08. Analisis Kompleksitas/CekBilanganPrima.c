#include <stdio.h>
#include <math.h>

int main() {
	int a,b,i,j,y;
	scanf("%d",&b);
	for(j=0;j<b;j++) {
		scanf("%d",&a);
		for(i=2;i<=trunc(sqrt(a));i++) {
			if (a%i == 0) {
				y = 1;
			}
		}
		if (y || a == 1) {
			y = 0;
			printf("BUKAN\n");
		}
		else {
			printf("YA\n");
		}
	}
}
