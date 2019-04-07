#include <stdio.h>
void maxHeapify(int n, int a[n], int i){
    int p = i;
    int item = a[p];
    int c = 2 * p + 1;
    while(c <= n - 1){
        if(c + 1 <= n - 1 && a[c] < a[c + 1])
            c = c + 1;
        if(item < a[c]){
            a[p] = a[c];
            p = c;
            c = 2 * p + 1;
        }
        else
            break;
    }
    a[p] = item;
}

void heapSort(int n, int a[n]){
	maxHeapify(n, a, 0);
	for(int k = n - 1; k >= 0; k--){
		int item = a[0];
		a[0] = a[k];
		a[k] = item;
		maxHeapify(k, a, 0);
	}
}

void buildMaxHeap(int n, int a[n]){
    for(int i = (n/2) - 1; i >= 0; i--){
        maxHeapify(n, a, i);
    }
}

void main() {
    int n;
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	printf("\nEnter the elements:\n");
	int a[n];
	for(int i = 0; i < n; i++){
	    scanf("%d", &a[i]);
	}
	buildMaxHeap(n, a);
	printf("\nLevel-order traversal of the heap is:\n");
	for(int i = 0; i < n; i++)
	    printf("%d ", a[i]);
	printf("\nPerforming heap sort:\n");
	heapSort(n, a);
	printf("\nThe sorted order is:\n");
	for(int i = n - 1; i >= 0; i--)
		printf("%d ", a[i]);
}
