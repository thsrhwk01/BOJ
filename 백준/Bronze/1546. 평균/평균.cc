#include <stdio.h>

int main(void) {
	int a, max = 0;
	double sum = 0;
	scanf("%d", &a);
	double b[a];

	for(int i = 0 ; i < a ; i++){
		scanf("%lf", &b[i]);
		if (max < b[i]) max = b[i];
	}

	for(int i = 0 ; i < a ; i++){
		b[i] = b[i]/max*100;
		sum += b[i];
	}

	printf("%.2lf", sum/a);

	return 0;
}