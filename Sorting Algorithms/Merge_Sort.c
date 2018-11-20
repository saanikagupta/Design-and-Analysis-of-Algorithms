//O(nlogn)
#include <stdio.h>
int n;
int merge(int a[],int low,int mid,int high){
	int i=low,j=mid+1,c[n],k=low;
	while((i<=mid) && (j<=high)){
		if(a[i]<=a[j]){
			c[k]=a[i];
			i=i+1;
			k=k+1;
		}

		else{
			c[k]=a[j];
			k=k+1;
			j=j+1;
		}
	}

	while(i<=mid){
		c[k]=a[i];
		i=i+1;
		k=k+1;
	}

	while(j<=high){
		c[k]=a[j];
		j=j+1;
		k=k+1;
	}

	for(i=low;i<=high;i++){
		a[i]=c[i];
	}
	return 0;
}


int mergeSort(int a[],int low,int high){
	int mid=0;
	if(low<high){
		mid=(low+high)/2;

		mergeSort(a,low,mid);
		mergeSort(a,mid+1,high);

		merge(a,low,mid,high);
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
	mergeSort(a,0,n-1);
	printf("\nThe array after merge sort is:\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}

/*Implementation

Enter the size of array:
5

Enter the elements:
-1 -3 0 1 1

The array after merge sort is:
-3 -1 0 1 1 

*/
