#include<stdio.h> 
#include<stdlib.h> 
   
struct node{ 
    int key; 
    struct node *left, *right; 
}; 
   

struct node *newNode(int key){
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
struct node* insert(struct node* node, int key){ 

    if (node == NULL) return newNode(key); 
  

    if (key < node->key) 
        node->left  = insert(node->left, key); 
        
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  

    return node; 
} 

void inorder(struct node *root){
	if(root != NULL){ 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
}

void Search(struct node *node, int key){
	if(node==NULL){
		printf("Value doesn't exist\n'");
	}
	if(node -> key == key){
		printf("Searching complete\n");
	}
	if(key < node -> key){
		Search(node -> left, key);
	}
	if(key > node -> key){
		Search(node -> right, key);
	}
}


int main(){
	struct node *root = NULL; 
    root = insert(root, 78); 
    
    insert(root, 45); 
    insert(root, 17); 
    insert(root, 32); 
    insert(root, 9); 
    insert(root, 58); 
    insert(root, 89); 
   
    inorder(root); 
    
    int num;
    printf("\nSearch the number: ");
    scanf("%d", &num);
    Search(root, num);
   
    return 0; 
} 
