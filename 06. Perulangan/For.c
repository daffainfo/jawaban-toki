#include <stdio.h>
int main () {
	int jumlah =0;
	int awal;
	int bil;
	int i;
	
	scanf("%d",&awal);
	for(i=0;i<awal;i++) {
		scanf("%d",&bil);
		jumlah+=bil;
	}
	printf("%d\n",jumlah);
}
