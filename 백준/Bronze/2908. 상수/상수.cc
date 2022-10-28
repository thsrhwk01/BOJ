#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	a = (a%10)*100 + (a%100-a%10) + (a/100);
	b = (b%10)*100 + (b%100-b%10) + (b/100);
	
	printf("%d", a > b ? a : b);
	return 0;
}