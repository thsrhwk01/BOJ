#include <stdio.h>

int main(void) {
	int how;
	scanf("%d", &how);

	for(int i = 0 ; i < how ; i++) {
		int a;
		char s[20];

		scanf("%d %s", &a, s);
		for(int j = 0 ; s[j] != NULL ; j++)
			for(int k = 0 ; k < a ; k++)
				printf("%c", s[j]);
		printf("\n");
	}

	return 0;
}