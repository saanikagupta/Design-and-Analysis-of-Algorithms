#include <stdio.h>
int printPath(int i,int path[]){
	if (path[i]==-1){
		printf("%d",i+1);
		return 0;
	}
	else{
		printPath(path[i],path);
		printf("--%d",i+1);
	}
	

	return 0;
}
int main(){
	int n,i,j;
	printf("\nEnter the number of nodes\n");
	scanf("%d",&n);
	int mat[n][n],source;
	printf("\nEnter the cost adjacency matrix(Enter infinity in case of no edge)\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	int path[n];
	printf("\nEnter the source node\n");
	scanf("%d",&source);
	source=source-1;
	int visited[n],set[n];
	for(i=0;i<n;i++){
		visited[i]=0;
		path[i]=source;
	}
	path[source]=-1;
	visited[source]=1;
	int start=source,p;
	int min=1000;
	int a,b;
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			if(visited[i]==1)
				continue;
			a=mat[source][i];
			b=mat[source][start]+mat[start][i];
			if(b<a){
				path[i]=start;
				mat[source][i]=b;
				if(min>b){
					min=b;
					p=i;
				}
			}
			else if(min>a){
				min=a;
				p=i;
			}
		}
		min=1000;
		start=p;
		visited[start]=1;
	}
	path[source]=-1;
	for(i=0;i<n;i++){
		printf("D%d%d : %d\n",source+1,i+1,mat[source][i]);
	}

/*	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
*/

	for(i=0;i<n;i++)
		printf("%d ",path[i]);

	printf("\n");
	for(i=0;i<n;i++){
		printPath(i,path);
		printf("\n");
	}


	return 0;
}


/*
Implementation-
Number of nodes : 9
Source vertex : 1
0 4 1000 1000 1000 1000 1000 8 1000
4 0 8 1000 1000 1000 1000 11 1000
1000 8 0 7 1000 4 1000 1000 2
1000 1000 7 0 9 14 1000 1000 1000
1000 1000 1000  9 0 10 1000 1000 1000    
1000 1000 4 14 10 0 2 1000 1000  
1000 1000 1000 1000 1000 2 0 1 6
8 11 1000 1000 1000 1000 1 0 7
1000 1000 2 1000 1000 1000 6 7 0

D11 : 0
D12 : 4
D13 : 12
D14 : 19
D15 : 21
D16 : 11
D17 : 9
D18 : 8
D19 : 14
-1 0 1 2 5 6 7 0 2 
1
1--2
1--2--3
1--2--3--4
1--8--7--6--5
1--8--7--6
1--8--7
1--8
1--2--3--9
*/
