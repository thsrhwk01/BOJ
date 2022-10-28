#include <stdio.h>

int main(void) {
	int a;
	scanf("%d", &a);

	for(int i = 0 ; i < a ; i++){
		printf("%d", a-i);
		if (i != a-1)
			printf("\n");
	}

	return 0;
}