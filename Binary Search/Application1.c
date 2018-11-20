/*
Given a sorted array of non-repeated integers A[1...n], n > 1 then check whether there is
an index i for which A[i] = i. Give an algorithm that runs in O(logn) time.
*/
#include<stdio.h>
int main(){
	int n,s,i;
	printf("\nEnter the size of array\n");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements (sorted and no repetition)\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int high=n-1,low=0,mid;
	while(low<=high){
		mid=(high+low)/2;
	
		if(mid==arr[mid]){
			printf("\nElement found\nIndex=%d",mid);
			return 0;
		}
	
		if(mid<arr[mid])
			high=mid-1;
	
		if(mid>arr[mid])
			low=mid+1;
	}
	
	printf("\nElement not found\n");
}

/*Implementation-

Example-1
Enter the size of array
5

Enter the elements (sorted and no repetition)
-1 2 3 4 5

Element not found

Example-2
Enter the size of array
5

Enter the elements (sorted and no repetition)
-2 1 3 4 5

Element found
Index=1
*/
