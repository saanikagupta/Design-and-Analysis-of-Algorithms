// Bottom-up Heap Construction
// Top-down Heap Construction
// Heapsort
// Insertion in Heap
// Deletion in Heap

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

void buildMaxHeapTopDown(int n, int a[n]){
    for(int i = 1; i <= n - 1; i++){
        int item = a[i];
        int c = i;
        int p = (c - 1)/2;
        while(item > a[p] && c > 0){
        	a[c] = a[p];
        	c = p;
        	p = (c - 1)/2;
        }
        a[c] = item;
    }
}

void buildMaxHeapBottomUp(int n, int a[n]){
    for(int i = (n/2) - 1; i >= 0; i--){
        maxHeapify(n, a, i);
    }
}

void insertHeap(int k, int a[k + 1]){
	int item = a[k];
	int c = k;
	int p = (c - 1)/2;
	while(item > a[p] && c > 0){
		a[c] = a[p];
		c = p;
		p = (c - 1)/2;
	}
	a[c] = item;
}

void deleteHeap(int del, int k, int a[k]){
	printf("\nDeleting %d: ", a[del]);
	a[del] = a[k - 1];
	k = k - 1;
	maxHeapify(k, a, del);
}

void main() {
    int n;
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	printf("\nEnter the elements:\n");
	int a[n + 1], b[n + 1];
	for(int i = 0; i < n; i++){
	    scanf("%d", &a[i]);
		b[i] = a[i];
	}

	// Heap construction
	buildMaxHeapBottomUp(n, a);
	buildMaxHeapTopDown(n, b);
	
	// Level-order traversal of Heap
	printf("\nLevel-order traversal of the heap is (bottom-up construction): ");
	for(int i = 0; i < n; i++)
	    printf("%d ", a[i]);
	printf("\nLevel-order traversal of the heap is (top-down construction): ");
	for(int i = 0; i < n; i++)
	    printf("%d ", b[i]);

	// Insertion
	int k;
	printf("\n\nInsert a new value in the heap: ");
	scanf("%d", &k);
	a[n] = k;
	insertHeap(n, a);
	printf("\nHeap after insertion is: \n");
	for(int i = 0; i <= n; i++)
		printf("%d ", a[i]);

	// Deletion
	int del;
	printf("\n\nEnter the position of node to be deleted (Select from 0 to %d): ", n);
	scanf("%d", &del);
	deleteHeap(del, n + 1, a);
	printf("\nHeap after deletion\n");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	
	//Heapsort
	printf("\n\nPerforming heap sort...\n");
	heapSort(n, a);
	printf("\nThe sorted order is: \n");
	for(int i = n - 1; i >= 0; i--)
		printf("%d ", a[i]);
}
