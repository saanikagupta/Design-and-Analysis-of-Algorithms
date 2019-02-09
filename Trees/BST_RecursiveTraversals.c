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

void main(){
	int option, val;
	node *ptr;
	int flag = 1;
	create_root(root);
	while(flag != 2){
		printf("\n\nChoose-\n1-Insert\n2-Recursive Preorder Traversal\n3-Recursive Postorder Traveral\n4-Recursive Inorder Traversal\n5-Exit\n");
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
			flag = 2;
			break;
		default:
			printf("\nWrong entry\n");
		}
	}
}
