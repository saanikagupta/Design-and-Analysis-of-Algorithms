//O(n*W)
#include<stdio.h> 

int max(int a, int b){ 
    return (a > b)? a : b; 
    
} 

int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
   for (i = 0; i <= n; i++){ 
       for (w = 0; w <= W; w++){ 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
   return K[n][W]; 
}
  
int main() 
{
	int n, wt[20], val[20], i, W;
	printf("Enter the number of items: ");
	scanf("%d", &n);
	printf("Enter the weights of items\n");
	for(i = 0; i<n; i++)
		scanf("%d", &wt[i]);
	printf("Enter the profits of items\n");
	for(i = 0; i<n; i++)
		scanf("%d", &val[i]);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);
    printf("The maximum profit earned = %d", knapSack(W, wt, val, n));
}

/* Implementation
Input-
Number of items : 4
Weights of items : 2 11 22 15
Profits of items : 11 21 31 33
Capacity of knapsack : 40

Output-
The maximum profit earned = 75
*/
