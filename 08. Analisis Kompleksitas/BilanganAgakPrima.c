#include <stdio.h>
#include <math.h>

long long int a,c,i,j,cek,tes,bts;

int main(void) {
	scanf("%ld",&a);
	for(i=1;i<=a;i++) {
		scanf("%d",&c);
		cek = 0;
		tes = 3;
		bts = trunc(c/2);
		if (c%2 == 0 && c!= 2 || c == 1) {
			cek++;
		}
		while(tes <= bts) {
			if (c % tes ==0) {
				cek++;
				if(cek > 2) {
					break;
				}
			}
			tes++;
		}
		if (cek > 2) {
			printf("BUKAN\n");
		}
		else {
			printf("YA\n");
		}
	}
}
