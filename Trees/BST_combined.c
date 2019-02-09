// Insertion, Recursive Traversals and Deletion Operations on a Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
int size = 0;
typedef struct mylist{
	int data;
	struct mylist *left;
	struct mylist *right;
}node;
node *root;
void create_root(node *root){
	root = NULL;
}

//Inserting nodes
node* insert(node *root, int val){
	node *ptr, *parentptr, *nodeptr;
	ptr = (node*)malloc(sizeof(node));
	ptr -> data = val;
	ptr -> left = NULL;
	ptr -> right = NULL;
	if(root == NULL)
		root = ptr;
	else{
		parentptr = NULL;
		nodeptr = root;
		while(nodeptr != NULL){
			parentptr = nodeptr;
			if(val < nodeptr -> data)
				nodeptr = nodeptr -> left;
			else
				nodeptr = nodeptr -> right;
		}
		if(val < parentptr -> data)
			parentptr -> left = ptr;
		else
			parentptr -> right = ptr;
	}
	return root;
}

// Recursive Traversals
void recursive_preorder(node *root){
	if(root != NULL){
		printf("%d\t", root -> data);
		recursive_preorder(root -> left);
		recursive_preorder(root -> right);
	}
}
void recursive_postorder(node *root){
	if(root != NULL){
		recursive_postorder(root -> left);
		recursive_postorder(root -> right);
		printf("%d\t", root -> data);
	}
}
void recursive_inorder(node *root){
	if(root != NULL){
		recursive_inorder(root -> left);
		printf("%d\t", root -> data);
		recursive_inorder(root -> right);
	}
}

// Iterative Traversals
void iterative_preorder(node *root){
	if(root != NULL){
		int top = -1;
		node** stack = (node**)malloc(size * sizeof(node*));
		node *cur;
		stack[++top] = root;
		while(top > -1){
			cur = stack[top--];
			printf("%d\t", cur -> data);
			if(cur -> right != NULL)
				stack[++top] = cur -> right;
			if(cur -> left != NULL)
				stack[++top] = cur -> left;
		}
	}
}

void iterative_postorder(node *root){
	if(root != NULL){
		int top1 = -1,top2 = -1;
		node *popped;
		node** stack1 = (node**)malloc(size * sizeof(node*));
		node** stack2 = (node**)malloc(size * sizeof(node*));
		stack1[++top1] = root;
		while(top1 > -1){
			popped = stack1[top1--];
			stack2[++top2] = popped;
			if(popped -> left != NULL)
				stack1[++top1] = popped -> left;
			if(popped -> right != NULL)
				stack1[++top1] = popped -> right;
		}
		while(top2 > -1){
			printf("%d\t", stack2[top2--] -> data);
		}
	}
}

void iterative_inorder(node *root){
	if(root != NULL){
		int top = -1, ovr = 0;;
		node *cur = root;
		node** stack = (node**)malloc(size * sizeof(node*));
		while(ovr == 0){
			if(cur != NULL){
				stack[++top] = cur;
				cur = cur -> left;
			}
			else{
				if(top > -1){
					cur = stack[top--];
					printf("%d\t", cur -> data);
					cur = cur -> right;
				}
				else{
					ovr = 1;
				}
			}	
		}
	}
}

void iterative_levelorder(node *root){
	if(root != NULL){
		int front = 0, rear = -1;
		node** queue = (node**)malloc(size * sizeof(node*));
		queue[++rear] = root;
		node *cur;
		while(front <= rear){
			cur=queue[front++];
			printf("%d\t",cur -> data);
			if(cur -> left != NULL)
				queue[++rear] = cur -> left;
			if(cur -> right != NULL)
				queue[++rear] = cur -> right;
		}
	}
}

// Counting the total number of nodes
int count_nodes(node *root)
{	if(root != NULL){
    	int count =  1;
        count += count_nodes(root -> left);
        count += count_nodes(root -> right);
        return count;
    }
    else
    	return 0;
}

// Deleting a node

node* inorder_successor(node* root) 
{ 
    node* cur = root; 
    while (cur -> left != NULL) 
        cur = cur -> left;  
    return cur; 
}

node* deleteNode(node* root, int key) 
{ 
    if (root == NULL){ 
    	printf("Value not found!");
    	return NULL;
    }
    if (key < root -> data)
        root -> left = deleteNode(root -> left, key); 
    else if (key > root -> data) 
        root -> right = deleteNode(root -> right, key); 
    else
    { 
        if (root -> left == NULL){
            node *temp = root -> right; 
            free(root);
            return temp; 
        }
        else if (root -> right == NULL){
            node *temp = root -> left; 
            free(root);
            return temp;  
        } 
        node* temp = inorder_successor(root -> right);  //Inorder successor (finding the minimum value node)
        root -> data = temp->data; 
        root -> right = deleteNode(root -> right, temp -> data); 
    }
    return root;
}

void main(){
	int option, val;
	node *ptr;
	int flag = 1;
	create_root(root);
	while(flag != 2){
		printf("\n\nChoose-\n1-Insert\n2-Recursive Preorder Traversal\n3-Recursive Postorder Traveral\n4-Recursive Inorder Traversal\n5-Iterative Preorder Traversal\n6-Iterative Postorder Traversal\n7-Iterative Inorder Traversal\n8-Level Order Traversal\n9-Count the total number of nodes\n10-Delete a node\n11-Exit\n");
		scanf("%d", &option);
		switch(option){
		case 1:{
			printf("\nEnter the value of new node:\t");
			size++;
			scanf("%d", &val);
			root = insert(root, val);
		}
		break;
		case 2:
			recursive_preorder(root);
			break;
		case 3:
			recursive_postorder(root);
			break;
		case 4:
			recursive_inorder(root);
			break;
		case 5:
			iterative_preorder(root);
			break;
		case 6:
			iterative_postorder(root);
			break;
		case 7:
			iterative_inorder(root);
			break;
		case 8:
			iterative_levelorder(root);
			break;
		case 9:{
			int	count = count_nodes(root);
			printf("%d ", count);
			break;
		}
		case 10:{
			int k;
			printf("Enter the value to delete:\t");
			scanf("%d",&k);
			root = deleteNode(root, k);
			size--;
			break;
		}
		case 11:
			flag = 2;
			break;
		default:
			printf("\nWrong entry\n");
		}
	}
}
