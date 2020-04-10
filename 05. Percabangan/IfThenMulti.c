#include <stdio.h>
int main () {
	int number;
	scanf("%d",&number);
	if (number>0 && number%2==0) {
		printf("%d\n",number);
	}
	else {
		printf("");
	}
}
