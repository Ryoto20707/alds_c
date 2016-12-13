#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int merge(int A[], int l, int mid, int r) {
	int n1 = mid - l, n2 = r - mid;
	int *L, *R;
	L = malloc(n1+1 * sizeof(int));
	R = malloc(n2+1 * sizeof(int));
	int i, j, k;
	for (i = 0; i < n1; i++) L[i] = A[l + i];
	for (i = 0; i < n2; i++) R[i] = A[mid + i];
	L[n1] = INT_MIN;
	R[n2] = INT_MIN;
	i = 0;
	j = 0;
	for (k = l; k < r; k++) {
		if (L[i] >= R[j]) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
	}
	free(L);
	free(R);
	return 1;
}

int mergeSort(int A[], int l, int r) {
	int cnt = 0;
	if (l + 1 < r) {
		int mid = (l + r) / 2;
		cnt+=mergeSort(A, l, mid);
		cnt+=mergeSort(A, mid, r);
		cnt+=merge(A, l, mid, r);
	}
	return cnt;
}

int main(void) {
	int n, *A, i, cnt;
	scanf("%d", &n);
	A = malloc(n * sizeof(int));
	for (i = 0; i < n; i++) scanf("%d", &A[i]);
	cnt = mergeSort(A, 0, n);
	for (i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i != n - 1) printf(" ");
	}
	printf("\n%d\n", cnt);
	return 0;
}