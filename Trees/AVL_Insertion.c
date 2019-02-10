// Insertion and Preorder Traversal of an AVL tree
#include <stdio.h>
#include <stdlib.h>
int size = 0;
typedef struct mylist{
	int data;
	struct mylist *left;
	struct mylist *right;
	int height;
}node;
node *root;
void create_root(node *root){
	root = NULL;
}

int height(node* v)  
{ 
   if(v == NULL)  
       return 0; 
   else{
   	int leftHeight = height(v -> left); 
       	int rightHeight = height(v -> right); 
  
        if (leftHeight > rightHeight)  
            return(leftHeight + 1); 
       	else return(rightHeight + 1); 
   } 
}

node* rightRotate(node *z){
	node *y = z -> left;
	node *RS2 = y -> right;
	y -> right = z;
	z -> left = RS2;

	z -> height = height(z);
	y -> height = height(y);

	return y;
}

node* leftRotate(node *z){
	node *y = z -> right;
	node *LS2 = y -> left;
	y -> left = z;
	z -> right = LS2;
	z -> height = height(z);
	y -> height = height(y);

	return y;
}

int BalanceFactor(node *v){
	if(v == NULL)
		return 0;
	return height(v -> left) - height(v -> right);
}
// inserting nodes
node* insert(node *root, int val){
	node *ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr -> data = val;
	ptr -> left = NULL;
	ptr -> right = NULL;
	ptr -> height = 1;
	if(root == NULL)
		return(ptr);
	if(val < root -> data)
		root -> left = insert(root -> left, val);
	else if(val > root -> data)
		root -> right = insert(root -> right, val);
	else
		return root;

	root -> height = height(root);
	int balance = BalanceFactor(root);

	// RR rotation
	if(balance > 1 && val < root -> left -> data)
		return rightRotate(root);

	// LL rotation
	if(balance < -1 && val > root -> right -> data)
		return leftRotate(root);

	// LR rotation
	if(balance > 1 && val > root -> left -> data){
		root -> left = leftRotate(root -> left);
		return rightRotate(root);
	}

	// RL rotation
	if(balance < -1 && val < root -> right -> data){
		root -> right = rightRotate(root -> right);
		return leftRotate(root);
	}
	return root;
}

void preorder(node *root){ 
    if(root != NULL){ 
        printf("%d\t", root -> data); 
        preorder(root -> left); 
        preorder(root -> right); 
    }
}

void main(){
	int option, val;
	node *ptr;
	int flag = 1;
	create_root(root);
	while(flag != 2){
		printf("\n\nChoose-\n1-Insert\n2-Preorder Traversal\n3-Exit\n");
		scanf("%d", &option);
		switch(option){
		case 1:{
			printf("\nEnter the value of new node:\t");
			size++;
			scanf("%d", &val);
			root = insert(root, val);
			break;
		}
		case 2:
			preorder(root);
			break;
		case 3:
			flag = 2;
			break;
		default:
			printf("\nWrong entry\n");
		}
	}
}
