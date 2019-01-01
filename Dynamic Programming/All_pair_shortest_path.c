//O(n^3)
#include <stdio.h>
#define SIZE 100
int print_path(int path[SIZE][SIZE],int a,int b){
	if(path[a][b]==-1){
		printf("%d---%d",a+1,b+1);
		return 0;	
	}
	else{
		printf("%d---",a+1);
		a=path[a][b];
		print_path(path,a,b);
		return 0;
	}
}

int main(){
	int i,j,k,n,a,b,c;
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	int mat[n][n],path[SIZE][SIZE];
	printf("\nEnter the adjacency matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[j][i]);
			path[j][i]=-1;
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(k==j)
					continue;
				a=mat[k][j];
				b=mat[k][i]+mat[i][j];
				if(b>=a)
					c=a;
				else
					c=b;
				mat[k][j]=c;
				if(b<a){
					path[j][k]=i;
				}
			}
		}
	}
	printf("\nThe final matrix is-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",mat[j][i]);
		}
		printf("\n");
	}
	printf("\nThe path matrix is-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",path[i][j]);
		}
		printf("\n");
	}

	printf("\nAll shortest paths are-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)
				continue;
			printf("Path between %d and %d:\t",i+1,j+1);
			print_path(path,i,j);
			printf("\n");
		}
	}
	return 0;
}



/*Implementation
Input-
Enter the number of vertices
4

Enter the adjacency matrix
0 3 999 999
999 0 12 5
4 999 0 -1
2 -4 999 0

Output-
The final matrix is-
0 3 15 8 
7 0 12 5 
1 -5 0 -1 
2 -4 8 0

The path matrix is=
-1 -1 1 1 
3 -1 -1 -1 
3 3 -1 -1 
-1 -1 1 -1

All shortest paths are-
Path between 1 and 2:	1---2
Path between 1 and 3:	1---2---3
Path between 1 and 4:	1---2---4
Path between 2 and 1:	2---4---1
Path between 2 and 3:	2---3
Path between 2 and 4:	2---4
Path between 3 and 1:	3---4---1
Path between 3 and 2:	3---4---2
Path between 3 and 4:	3---4
Path between 4 and 1:	4---1
Path between 4 and 2:	4---2
Path between 4 and 3:	4---2---3
*/
