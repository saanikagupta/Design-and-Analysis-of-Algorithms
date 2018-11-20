//O(n^2)
#include<stdio.h>
int main(){
	int n,i,j,k,size;
	float max;
	printf("\nEnter the number of jobs:\n");
	scanf("%d",&n);
	float p[n],pcopy[n];
	int d[n],pr[n];
	printf("\nEnter the deadlines:\n");
	for(i=0;i<n;i++){
		scanf("%d",&d[i]);
	}
	printf("\nEnter the corresponding profits\n");
	for(i=0;i<n;i++){
		scanf("%f",&p[i]);
	}
	for(i=0;i<n;i++)
		pcopy[i]=p[i];

	//Finding the priority indexes
	for(i=0;i<n;i++){
		max=pcopy[0];
		k=0;
		for(j=0;j<n;j++){
			if(max<pcopy[j]){
				k=j;
				max=pcopy[j];
			}
		}
		pr[i]=k;
		pcopy[k]=-100;
	}

	//Calculating max deadline to find the size of sequence
	size=d[0];
	for(i=0;i<n;i++){
		if(size<d[i]){
			size=d[i];
		}
	}
	int seq[size];
	for(i=0;i<size;i++){
		seq[i]=-100;
	}

	for(i=0;i<n;i++){
		if(seq[d[pr[i]]]==-100)
			seq[d[pr[i]]]=pr[i];
		else{
			for(j=d[pr[i]]-1;j>=0;j--){
				if(seq[j]==-100){
					seq[j]=pr[i];
					break;
				}	
			}
		}
	}
	//Calculating profit
	float profit=0;
	for(i=0;i<size;i++){
		if(seq[i]!=-100)
			profit=profit+p[seq[i]];
	}
	printf("\nMaximum profit = %f\n",profit);
	return 0;
}

/*Implementation-
Example-1
Enter the number of jobs:
7

Enter the deadlines:
2 4 3 1 3 1 2

Enter the corresponding profits
30 20 18 6 5 3 1

Maximum profit = 74.000000

Example-2
Enter the number of jobs:
5

Enter the deadlines:
1 2 4 1 3

Enter the corresponding profits
1 5 20 15 10

Maximum profit = 50.000000
*/
