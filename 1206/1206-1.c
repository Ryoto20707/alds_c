#include <stdio.h>

long fact(long n) {
	if (n < 2) return 1;
	return n * fact(n - 1);
}

int main(void) {
	long n;
	scanf("%ld", &n);
	printf("%ld\n", fact(n));
	return 0;
}