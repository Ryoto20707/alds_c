#include <stdio.h>
#include <stdlib.h>

int max_divide(int A[], int left, int right) {
	if(right < 0) exit (1);
	if (right - left == 0) {
		printf("%d\n", A[left]);
		return left;
	}
	else {
		int max_l, max_r;
		max_l = max_divide(A, left, (left + right) / 2);
		max_r = max_divide(A, (left + right) / 2 + 1, right);
		if(A[max_l] > A[max_r]) {
			printf("%d\n", A[max_l]);
			return max_l;
		}
		else {
			printf("%d\n", A[max_r]);
			return max_r;
		}
	}
}

int main(void) {
	int *A, n, i;
	scanf("%d", &n);
	A = malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	max_divide(A, 0, n-1);
}