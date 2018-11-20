/*
Given an array of n elements, give an algorithm for finding the element which appears
maximum number of times in the array in O(nlogn) time.
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
    i=0;
    int j=i+1,count=1,maxCount=1,f=0;
    int arr1[n],arr2[n];
    for(i=0;i<n-1;i++){
    	if(a[i]==a[i+1]){
            count++;
        }
        //printf("%d %d %d %d %d\n",count,a[i],a[j],i,j);
        else if(count>1){
            //printf("%d repeated %d times\n",a[i],count);
            arr1[f]=count;
            arr2[f]=a[i];
            f++;
            if(count>maxCount)
            	maxCount=count;
            count=1;
        }
    }
    for(i=0;i<f;i++){
        if(arr1[i]==maxCount)
            printf("\n%d repeated %d times\n",arr2[i],arr1[i]);
    }
    if(f==0){
        printf("\nNo repetitions\n");
    }
    return 0;
}

/*Implementation

Example-1
Enter the size of array:
7

Enter the elements:
-6 7 6 6 8 6 -6 

6 repeated 3 times

Example-2
Enter the size of array:
7 

Enter the elements:
-7 -9 7 -7 -9 8 9

-9 repeated 2 times

-7 repeated 2 times


*/
