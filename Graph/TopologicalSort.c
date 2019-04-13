// Topoligical Sorting by Source Removal Method
#include <stdio.h>
void main(){
	int n, i, j;
	printf("\nEnter the number of nodes: ");
	scanf("%d", &n);
	int a[n][n], id[n];
	int stack[n], top = -1;
	int order[n], t = 0;
	printf("\nEnter the adjacency matrix:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	// Finding the indegree of vertices
	for(i = 0; i < n; i++){
		int sum = 0;
		for(j = 0; j < n; j++){
			if(i != j){
				sum = sum + a[j][i];
			}
		}
		id[i] = sum;
	}

	for(i = 0; i < n; i++){
		if(id[i] == 0)
			stack[++top] = i;
	}
	int flag = 0;
	if(top != -1){
		flag = 1;
		printf("Topological Sort: ");
	}

	while(top > -1){
		int u = stack[top--];
		order[t++] = u;
		for(i = 0; i < n; i++){
			if(a[u][i] == 1){
				id[i] = id[i] - 1;
				if(id[i] == 0){
					stack[++top] = i;
				}
			}
		}
	}
	if(flag == 1){
		for(i = 0; i < n; i++)
			printf("%d ", order[i]);
	}

	else{
		printf("\nIt's not a Directed Acyclic Graph!");
	}
}

// Implementation:

// Example-1:
// n = 6
// 0 0 1 1 0 0
// 0 0 0 1 1 0
// 0 0 0 0 0 1
// 0 0 0 0 0 1
// 0 0 0 0 0 1
// 0 0 0 0 0 0

// Topological Sort: 1 4 0 3 2 5

// Example-2:
// n = 3
// 0 1 0
// 0 0 1
// 1 0 0

// It's not a Directed Acyclic Graph!
