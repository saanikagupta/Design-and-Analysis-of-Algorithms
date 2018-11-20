int n,count=1;
int mstcost=0;
#include <stdio.h>
int makeParent(int parent[],int row,int col){
	int i;
	if(parent[row]!=parent[col]){
		for(i=0;i<n;i++){
			if(parent[i]==parent[col]){
				parent[i]=parent[row];
			}
		}
		printf("\n%d--%d\t(edge %d)\n",row+1,col+1,count);
		count=count+1;
		return 1;
	}
	return 0;
}
int main(){
	int i,j;
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	int cost[n][n];
	printf("\nEnter the cost adjacency matrix(Must be symmetric and enter infinity in case of no edge):\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	int parent[n],val;
	for(i=0;i<n;i++){
		parent[i]=i;
	}
	int min=999,row,col;
	while(count<n){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(cost[i][j]<min && i!=j){
					row=i;
					col=j;
					min=cost[i][j];
				}
			}
		}
		val=makeParent(parent,row,col);
		if(val==1){
			mstcost=mstcost+cost[row][col];
		}
		min=999;
		cost[row][col]=cost[col][row]=min;
	}
	printf("\nThe cost of MST = %d\n",mstcost);
/*	
	for(i=0;i<n;i++){
		printf("%d\t",parent[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
*/
	return 0;
}

/*Implementation-

Example-1
0 10 1000 30 45 1000
10 0 50 1000 40 25
1000 50 0 1000 35 15
30 1000 1000 0 1000 20
45 40 35 1000 0 70
1000 25 15 20 70 0

1--2	(edge 1)

3--6	(edge 2)

4--6	(edge 3)

2--6	(edge 4)

3--5	(edge 5)

The cost of MST = 105

Example-2
0 2 1000 6 1000
2 0 3 8 5
1000 3 0 1000 7
6 8 1000 0 9
1000 5 7 9 0

1--2	(edge 1)

2--3	(edge 2)

2--5	(edge 3)

1--4	(edge 4)

The cost of MST = 16
*/
