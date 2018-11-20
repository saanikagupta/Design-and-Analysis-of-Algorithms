//O(n^3)
#include<stdio.h>
int main(){
	int i,j,n,f,kval,min,k;
	printf("\nEnter the total number of matrices:\n");
	scanf("%d",&n);
	int cost[n+1],karr[n][n],mat[n][n];
	printf("Enter the values of:\n");
	for(i=0;i<=n;i++){
		printf("P%d :\t",i);
		scanf("%d",&cost[i]);
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			mat[i][j]=100000;
			karr[i][j]=0;
		}
	  for(int g=0;g<n;g++){
		  for(int i=0;i<n;i++){
			  j=i+g;
			  if(i==j){
				  mat[i][j]=0;
			  }
			  else{
				  int min=1000000;
				  for (int k=i;k<=j-1;k++){
					  f=mat[i][k]+mat[k+1][j]+cost[i]*cost[k+1]*cost[j+1];
					  if(f<min){
						  min=f;
						  karr[i][j]=k+1;
					  }
				  }
			  mat[i][j]=min;
			}
		}
	}
	for(i=0;i<n;i++)
			printf("M%d%d = 0\n",i+1,i+1);
	k=0;
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			printf("M%d%d = %d\t( k = %d )\n",j+1,i+1,mat[j][i],karr[j][i]);
		}
		k=k+1;
	}

	printf("\nMinimum number of scalar multiplications required : %d",mat[0][n-1]);
	return 0;
}

/*Implementation

Enter the total number of matrices:
4
Enter the values of:
P0 :	5
P1 :	4
P2 :	6
P3 :	2
P4 :	7
M11 = 0
M22 = 0
M33 = 0
M44 = 0
M12 = 120	( k = 1 )
M13 = 88	( k = 1 )
M23 = 48	( k = 2 )
M14 = 158	( k = 3 )
M24 = 104	( k = 3 )
M34 = 84	( k = 3 )

Minimum number of scalar multiplications required : 158

*/
