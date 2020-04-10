#include <stdio.h>
int main() {
	int a,b,jumlah[1000],max,min;
	scanf("%d",&a);
	
	for(b=1;b<=a;b++) {
		scanf("%d",&jumlah[b]);
	}
	max=jumlah[1];
	min=jumlah[1];
	
	for(b=1;b<=a;b++) {
		if (jumlah[b]>=max) {
			max=jumlah[b];
		}
		else if (jumlah[b]<=min) {
			min=jumlah[b];
		}
	}
	printf("%d %d\n",max,min);
}
