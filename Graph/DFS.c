#include <stdio.h>
void main(){
	int n, u, stack[n], flag = 0;
	printf("\nEnter the number of vertices:\n");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	int adj[n][n], vis[n], i, j, top = -1;
	for(i = 0; i<n; i++){
		vis[i] = 0;
		stack[i] = 0;
		for(j = 0; j < n; j++){
			scanf("%d", &adj[i][j]);
		}
	}
	u = 0;
	vis[u] = 1;
	stack[++top] = u;
	printf("%c ",u + 'a');
	int count = 1;
	while(top > -1 || count < n){
		flag = 0;
		if(top == -1){
			printf("\n");
			for(i = 0; i < n; i++){
				if(vis[i]==0){
					u = i;
					printf("%c ",u+'a');
					stack[++top] = u;
					vis[u] = 1;
					count++;
					break;
				}
			}
		}

		for(j = 0; j < n; j++){
			if(vis[j] == 0 && adj[u][j] == 1){
				u = j;
				vis[u] = 1;
				stack[++top] = u;
				printf("%c ",u + 'a');
				count++;
				flag=1;
				break;
			}	
		}
		if(flag == 0){
			top = top-1;
			u = stack[top];
		}
	}
}

/*
Example 1-
0 1 1 1 1 0 0
1 0 0 1 0 1 0
1 0 0 0 0 0 1
1 1 0 0 0 1 0
1 0 0 0 0 0 1
0 1 0 1 0 0 0
0 0 1 0 1 0 0
a b d f c g e

Example 2 (Disconnected)-
0 0 1 1 1 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
1 0 0 1 0 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0
1 1 0 0 0 1 0 0 0 0
0 1 1 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 1 0 1 0
0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 1 0 1 0
a c d f b e
g h i j
*/
