#include <stdio.h>
#include <string.h>

int main(void) {
	char s[1000001];
	int count[26] = {0, };

	scanf("%s", s);
	int len = strlen(s);

	for(int i = 0 ; i < len ; i++) {
		if(s[i] >= 97)
			s[i] -= 32;
		count[s[i]-65]++;
	}

	int prt = 0, check = 0, high = 0;

	for(int i = 0 ; i < 26 ; i++) {
		if(count[i] > high) {
			high = count[i];
			prt = i+65;
			check = 0;
		}
		else if(count[i] == high)
			check = 1;
	}

	if(check == 1)
		printf("?");
	else
		printf("%c", prt);

	return 0;
}