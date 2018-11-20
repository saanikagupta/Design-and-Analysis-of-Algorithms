#include <stdio.h>
int rear=-1;
int front=0;
int queue[20];
int count=0;
int del;
int pop(int queue[],int n){
	if(front==0 && rear==-1)
		return -1;
	else{
		del=queue[front];
		front=front+1;
	}
	if(front>rear){
		front=0;
		rear=-1;
	}
	return del;
}
int main(){
	int n,u,i,j;
	printf("\nEnter the number of nodes:\t");
	scanf("%d",&n);
	int mat[n][n];
	int v[n];
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	printf("The BFS traversal is:\n");
	for(i=0;i<n;i++){
		queue[i]=0;
		v[i]=0;
	}
	v[0]=1;
	queue[++rear]=0;
	while(front<=rear || count<n){
		u=pop(queue,n);
		if(u==-1){
			printf("\n");
			for(i=0;i<n;i++){
				if(v[i]==0){
					u=i;
					break;
				}
			}
			queue[++rear]=u;
			v[u]=1;
			u=pop(queue,n);
		}
		printf("%c ",u+'a');
		count=count+1;

		for(i=0;i<n;i++){
			if(mat[u][i]==1 && u!=i){
				if(v[i]==0){
					queue[++rear]=i;
					v[i]=1;
				}
			}
		}
	}
/*
	printf("\n");

	for(i=0;i<n;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
	printf("%d %d %d",count,front,rear);
*/
	return 0;
}


/*
Implementation-

Example-1
7 nodes
0 1 1 1 1 0 0
1 0 0 1 0 1 0
1 0 0 0 0 0 1
1 1 0 0 0 1 0
1 0 0 0 0 0 1
0 1 0 1 0 0 0
0 0 1 0 1 0 0

a-b-c-d-e-f-g

Example-2
10 nodes (Disconnected Graph)
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

a-c-d-e-f-b
g-h-j-i
*/
