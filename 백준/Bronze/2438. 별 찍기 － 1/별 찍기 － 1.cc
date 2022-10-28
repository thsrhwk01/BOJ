#include <stdio.h>

int main(void) {
	int a;
	scanf("%d", &a);

	for(int i = 1 ; i < a+1 ; i++) {
		for(int j = 0 ; j < i ; j++)
			printf("*");
		if(i+1 != a+1)
			printf("\n");
	}

	return 0;
}