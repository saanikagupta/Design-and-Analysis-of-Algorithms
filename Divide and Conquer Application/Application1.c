/*
Given an array of n elements. Find whether there are three elements in the array such
that their sum is equal to given element K or not? in O(n^2) time
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
	int i,flag=0;
	printf("\nEnter the size of array:\n");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	mergeSort(a,0,n-1);
	int sum;
	printf("\nEnter the sum\n");
	scanf("%d",&sum);
	int l, r;
    	for (i=0;i<n-2;i++){
        	l=i+1;
 		r=n-1;
        	while(l<r){
            		if(a[i]+a[l]+a[r]==sum) {
                		printf("Triplet is %d, %d, %d", a[i],a[l], a[r]);
                		flag=2;
                		break;
            		}
            		else if(a[i]+a[l]+a[r]<sum)
                		l++;
            		else
                		r--;
        	}
    	}
    	if(flag==0)
    		printf("\nTriplet doesn't exist for the given sum");
	return 0;
}

/*Implementation

Example-1
Enter the size of array:

6

Enter the elements:
2 -1 0 2 3 4

Enter the sum
1
Triplet is -1, 0, 2

Example-2
Enter the size of array:
6

Enter the elements:
2 -1 0 2 3 4

Enter the sum
-1

Triplet doesn't exist for the given sum

Example-3
Enter the size of array:
2

Enter the elements:
-1 2

Enter the sum
1

Triplet doesn't exist for the given sum

*/
