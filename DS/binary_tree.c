#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 30
 
struct treeNode {
	char name[max];
	struct treeNode* left;
	struct treeNode* right;
};
 
struct treeNode* createNode (char name[max]) {
	struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
	strcpy(newNode->name,name);
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
 
void inorderRecursive (struct treeNode* root){
	if ( root == NULL ){
		return;
	}
	inorderRecursive(root->left);
	printf ("%s\n",root->name);
	inorderRecursive(root->right);
}
 
void preorderRecursive (struct treeNode* root){
	if ( root == NULL ){
		return;
	}
	printf ("%s\n",root->name);
	preorderRecursive (root->left);
	preorderRecursive (root->right);
}
 
void postorderRecursive (struct treeNode* root){
	if ( root == NULL ){
		return;
	}
	postorderRecursive (root -> left);
	postorderRecursive (root -> right);
	printf ("%s\n",root->name);
}
 
void inorderNonRecursive(struct treeNode* root) {
    struct treeNode* stack[100];
    int top = -1;
    struct treeNode* curr = root;
 
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%s\n", curr->name);
        curr = curr->right;
    }
}
 
void preorderNonRecursive(struct treeNode* root) {
    if (root == NULL)
        return;
 
    struct treeNode* stack[100];
    int top = -1;
    stack[++top] = root;
 
    while (top != -1) {
        struct treeNode* curr = stack[top--];
        printf("%s\n", curr->name);
 
        if (curr->right)
            stack[++top] = curr->right;
        if (curr->left)
            stack[++top] = curr->left;
    }
}
 
void postorderNonRecursive(struct treeNode* root) {
    if (root == NULL)
        return;
 
    struct treeNode* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
 
    while (top1 != -1) {
        struct treeNode* curr = stack1[top1--];
        stack2[++top2] = curr;
 
        if (curr->left)
            stack1[++top1] = curr->left;
        if (curr->right)
            stack1[++top1] = curr->right;
    }
 
    while (top2 != -1) {
        struct treeNode* curr = stack2[top2--];
        printf("%s\n", curr->name);
    }
}
 
int main(){
	struct treeNode* root = createNode("Soham");
	root->right = createNode ("Shivank");
	root->left = createNode ("Ajay");
	root->left->right = createNode("Faiza");
	root->left->left = createNode ("Tanishka");
	root->right->right = createNode("Nikhil");
	root->right->left = createNode ("Krishna");
 
	printf("Recursive In-Order Traversal: \n");
	inorderRecursive (root);
	printf ("\n");
 
	printf("Recursive Pre-Order Traversal: \n");
	preorderRecursive (root);
	printf ("\n");
 
	printf("Recursive Post-Order Traversal: \n");
	postorderRecursive (root);
	printf ("\n");
 
	printf("Non-Recursive In-Order Traversal: \n");
	inorderNonRecursive (root);
	printf ("\n");
 
	printf("Non-Recursive Pre-Order Traversal: \n");
	preorderNonRecursive (root);
	printf ("\n");
 
	printf("Non-Recursive Post-Order Traversal: \n");
	postorderNonRecursive (root);
	printf ("\n");
}