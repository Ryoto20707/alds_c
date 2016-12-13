#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int search(int A[], int l, int r) {
	int min;
	if (r-l == 1) {
		min = A[l];
	}
	else {
		int mid = (l + r) / 2;
		int n1, n2;
		n1 = search(A, l, mid);
		n2 = search(A, mid, r);
		if (n1 < n2) min = n1;
		else min = n2;
	}
	printf("%d\n", min);
	return min;
}

int main(void) {
	int n, *A, i;
	scanf("%d", &n);
	A = malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	search(A, 0, n);
	return 0;
}