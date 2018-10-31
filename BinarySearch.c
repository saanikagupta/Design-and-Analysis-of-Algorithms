#include <stdio.h>

int binarySearch(int a[], int length, int key)
{
	int mid, l = 0;
	int h = length - 1;
	while(l<=h){
		mid = (l+h)/2;
		if(a[mid] == key){
			return mid;
		}
		else if(a[mid]>key){
			h = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	return -1;
}

int main(){
	int length, i;
	printf("Enter length of array\n");
	scanf("%d", &length);
	int a[length];
	printf("Enter sorted array\n");
	for(i = 0; i < length; i++ ){
		scanf("%d", &a[i]);
	}
	printf("Enter key to search\n");
	int key;
	scanf("%d", &key);
	int result = binarySearch(a, length, key);
	if(result == -1 )
		printf("Element not found");
	else
		printf("Element found at position %d", result+1);
	
}
