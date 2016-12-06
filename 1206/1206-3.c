#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
	int *A, n, i, j, min;
	while (1) {
		min = INT_MAX;
		scanf("%d", &n);
		if (n == 0) return 0;
		A = malloc(n * sizeof(int));
		for (i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++)
			if (abs(A[i] - A[j]) < min) min = abs(A[i] - A[j]);
		}
		printf("%d\n", min);
	}
}