#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int canMake(int A[], int len, int b) {
	int i, j, limit, sum, code;
	for (i = 0; i < len; i++) {
		if(A[i] > b) break;
	}
	if (A[i] > b) i--;
	limit = i;
	for (i = 0; i <= (int)pow(2, limit+1); i++) {
		code = i;
		sum = 0;
		for (j = limit; j >= 0; j--) {
			if(code > (int)pow(2, j)) {
				code -=(int)pow(2, j);
				sum += A[j];
			}
		}
		if (sum == b) return 1;
	}
	return 0;
}

void sort(int A[], int len){
	int i, j;
	int tmp, min;
	for (i = 0; i < len - 1; i++) {
		min = i;
		for (j = i + 1; j < len; j++) {
			if(A[j] < A[min]) min = j;
		}
		if(min != i) {
			tmp = A[i];
			A[i] = A[min];
			A[min] = tmp;
		}
	}
}

int main(void) {
	int *A, b, n, q, i;
	scanf("%d", &n);
	A = malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, n);
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &b);
		if(canMake(A, n, b)) printf("true\n");
		else printf("false\n");
	}
	return 0;
}
