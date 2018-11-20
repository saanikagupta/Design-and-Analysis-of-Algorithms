//Prim's Algorithm better than Kruskal's for dense graph
#include <stdio.h>
int main(){
	int n;
	int mst=0;
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	int vis[n],mat[n][n],i,j,col,row,count=1;
	for(i=0;i<n;i++)
		vis[i]=0;
	printf("\nEnter the cost adjacency matrix(Must be symmetric and enter infinity in case of no edge)\n");
	int min=9999;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
			if(mat[i][j]<min && i!=j){
				min=mat[i][j];
				row=i;
				col=j;
			}
		}
	int flag=2;
	vis[row]=vis[col]=1;
	printf("\n%c--%c\tedge = %d\n",'A'+row,'A'+col,count);
	mst+=mat[row][col];
	count=count+1;
	while(flag<n){
		min=9999;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if((vis[j]==1) && (vis[i]==0) && i!=j){
					if(mat[j][i]<min){
						min=mat[j][i];
						row=j;
						col=i;
					}
				}
			}
		}
		vis[row]=vis[col]=1;
		mst+=mat[row][col];
		printf("%c--%c\tedge = %d\n",'A'+col,'A'+row,count);
		count=count+1;
		flag=flag+1;
	}
	printf("\nThe cost of MST = %d\n",mst);
	return 0;
}
/*Implementation

Example-1
0 2 1000 6 1000
2 0 3 8 5
1000 3 0 1000 7
6 8 1000 0 9
1000 5 7 9 0 

A--B	edge = 1
C--B	edge = 2
E--B	edge = 3
D--A	edge = 4

The cost of MST = 16


Example-2
0 10 1000 30 45 1000
10 0 50 1000 40 25
1000 50 0 1000 35 15
30 1000 1000 0 1000 20
45 40 35 1000 0 70
1000 25 15 20 70 0

A--B	edge = 1
F--B	edge = 2
C--F	edge = 3
D--F	edge = 4
E--C	edge = 5

The cost of MST = 105
*/
