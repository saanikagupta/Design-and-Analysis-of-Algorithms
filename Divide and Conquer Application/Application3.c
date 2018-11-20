/*
Let A and B be two arrays of n elements. Given a number K, draw an O(nlogn) time
algorithm for determining whether there exists a ∈ A, b ∈ B such that a + b = K or not?
*/
#include<stdio.h>
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
	printf("\nEnter the elements of first array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	mergeSort(a,0,n-1);
	int s,flag=0;
	int arr[n];
	printf("\nEnter the elements of second array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int high=n-1,low=0,mid=(low+high)/2;
	printf("\nEnter the sum\n");
	scanf("%d",&s);
  	int newkey;
	for(i=0;i<n;i++){
		high=n-1;
		low=0;
		newkey=s-arr[i];
		while(low<=high){
			mid=(high+low)/2;

			if(a[mid]==newkey){
				printf("\nFound\n");
				flag=1;
				break;
			}

			if(a[mid]>newkey)
				high=mid-1;

			if(a[mid]<newkey)
				low=mid+1;
		}
    	if(flag==1)
		    break;	
    }    	
	
	if(flag==0)
	  printf("\nNot Found\n");
	return 0;
}

/*Implementation

Example-1
Enter the size of array:
2

Enter the elements of first array:
1 -1

Enter the elements of second array
0 1

Enter the sum
2

Found

Example-2
Enter the size of array:
5

Enter the elements of first array:
1 0 1 -2 1

Enter the elements of second array
3 -1 2 1 3

Enter the sum
6

Not Found

*/
