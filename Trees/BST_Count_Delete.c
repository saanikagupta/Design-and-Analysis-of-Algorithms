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

node* inorder_successor(node* root){ 
    node* cur = root; 
    while (cur -> left != NULL) 
        cur = cur -> left;  
    return cur; 
}

node* deleteNode(node* root, int key){ 
    if (root == NULL){ 
    	printf("Value not found!");
    	return NULL;
    }
    if (key < root -> data)
        root -> left = deleteNode(root -> left, key); 
    else if (key > root -> data) 
        root -> right = deleteNode(root -> right, key); 
    else{ 
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
		printf("\n\nChoose-\n1-Insert\n2-Count the total number of nodes\n3-Delete a node\n4-Exit\n");
		scanf("%d", &option);
		switch(option){
		case 1:{
			printf("\nEnter the value of new node:\t");
			size++;
			scanf("%d", &val);
			root = insert(root, val);
		}
		break;
		case 2:{
			int	count = count_nodes(root);
			printf("%d ", count);
			break;
		}
		case 3:{
			int k;
			printf("Enter the value to delete:\t");
			scanf("%d",&k);
			root = deleteNode(root, k);
			size--;
			break;
		}
		case 4:
			flag = 2;
			break;
		default:
			printf("\nWrong entry\n");
		}
	}
}
