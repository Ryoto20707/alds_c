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
	int M, Nmin, Nmax, N, Nans = 0, *P, i, gap = INT_MIN;
	scanf("%d %d %d", &M, &Nmin, &Nmax);
	P = malloc(M * sizeof(int));
	for (i = 0; i < M; i++) {
		scanf("%d", &P[i]);
	}
	mergeSort(P, 0, M);
	for (i = 0; i < M - 1; i++) {
		N = i+1;
		if (N>=Nmin && N<=Nmax && P[i]-P[i+1]>gap) {
			gap = P[i] - P[i+1];
			Nans = N;
		}
	}
	printf("%d\n", Nans);
	return 0;
}