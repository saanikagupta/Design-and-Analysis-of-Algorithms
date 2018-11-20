//O(n^2)
#include<stdio.h>
int n;
int partition(int a[],int low,int high){
	int piv=a[low];
	int i=low;
	int t;
	int j=high+1;
	while(i<=j){
		do{
			i=i+1;
		}while(piv>=a[i]);
		do{
			j=j-1;
		}while(piv<a[j]);
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	t=a[j];
	a[j]=a[low];
	a[low]=t;
	return j;
}

int quickSort(int a[],int low,int high){
	if(low<high){
		int k=partition(a,low,high);
		quickSort(a,low,k-1);
		quickSort(a,k+1,high);
	}
	return 0;
}


int main(){
	int i;
	printf("\nEnter the size of array:\n");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}	
	printf("\nEnter the last element (not included in the dataset and should be largest of all):\n");
		scanf("%d",&a[n]);
	quickSort(a,0,n-1);
	printf("\nThe array after quick sort is:\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}

/*Implementation

Enter the size of array:
6

Enter the elements:
-1 2 3 0 1 2

Enter the last element (not included in the dataset and should be largest of all):
1000

The array after quick sort is:
-1 0 1 2 2 3

*/
