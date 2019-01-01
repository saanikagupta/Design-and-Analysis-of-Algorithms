/*
Given an array of n elements, give an algorithm for checking whether there are any duplicate elements in the array or not? 
In O(nlogn) time.
*/

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
	int flag=1;
	for(i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\nNo duplicates!");
	}
	else{
		printf("\nDuplicates Found!");
	}
	return 0;
}

/* Implementation
7 5 77 9 -1 2 1 3
No duplicates!

1 3 2 1
Duplicates Found!
*/
