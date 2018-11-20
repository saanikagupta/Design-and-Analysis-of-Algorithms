//O(n) if priority array is given
//Here, O(n^2)
#include<stdio.h>
void main(){
	int m,n,i,j,k=0;
	printf("\nEnter the capacity M of knapsack:\n");
	scanf("%d",&m);
	printf("\nEnter the number of objects:\n");
	scanf("%d",&n);
	int pr[n],ckc=m;
	float w[n],p[n],pw[n],x[n];
	printf("\nEnter the weights of the objects:\n");
	for(i=0;i<n;i++)
		scanf("%f",&w[i]);
	printf("\nEnter the profits:\n");
	for(i=0;i<n;i++)
		scanf("%f",&p[i]);
	for(i=0;i<n;i++)
		pw[i]=p[i]/w[i];
	float max=pw[0];
	for(j=0;j<n;j++){
		k=0;
		for(i=0;i<n;i++){
			if(pw[i]>max){
				max=pw[i];
				k=i;
			}
		}
		pr[j]=k;
		pw[k]=-1;
		max=pw[0];
	}
/*
	for(i=0;i<n;i++)
		printf("%d ",pr[i]);
*/	
	for(i=0;i<n;i++){
		if(ckc>=w[pr[i]]){
			x[pr[i]]=1;
			ckc=ckc-w[pr[i]];
		}
		else
			break;
	}
	if(i<n){
		x[pr[i]]=ckc/w[pr[i]];
		i=i+1;
		for(;i<n;i++)
			x[pr[i]]=0;
	}	
	for(i=0;i<n;i++){
		printf("x%d=%f ",i+1,x[i]);
	}
	printf("\nThe optimal solution is-");
	float profit=0;
	for(i=0;i<n;i++)
		profit=profit+p[i]*x[i];
	printf("\nThe total profit is %f",profit);
}

/*Implementation-

Enter the capacity M of knapsack:
20

Enter the number of objects:
3

Enter the weights of the objects:
18 15 10

Enter the profits:
25 24 15
x1=0.000000 x2=1.000000 x3=0.500000 
The optimal solution is-
The total profit is 31.500000
*/
