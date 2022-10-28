#include <stdio.h>

int main(void) {
	int h, m, sum;
	scanf("%d %d", &h, &m);
	sum = h*60+m-45;
	if(sum < 0)
		sum += 1440;
	else if(sum >1439)
		sum -= 1440;

	printf("%d %d", sum/60, sum%60);

	return 0;
}