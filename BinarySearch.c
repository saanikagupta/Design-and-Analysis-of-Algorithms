#include <stdio.h>

int binarySearch(int a[], int length)
{
	int mid, l = 1;
	int h = length;
	while(l<=h){
		mid = (l+h)/2;
		if(a[mid] == mid){
			return mid;
		}
		else if(a[mid]>mid){
			h = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	return 0;
}

int main(){
	int length, i;
	printf("Enter length of array\n");
	scanf("%d", &length);
	int a[length+1];
	printf("Enter sorted array\n");
	for(i = 1; i <= length; i++ ){
		scanf("%d", &a[i]);
	}
	int result = binarySearch(a, length);
	if(result == 0)
		printf("Element not found");
	else
		printf("Element found at position %d", result);
	
}
