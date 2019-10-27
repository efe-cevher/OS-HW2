#include<stdio.h>
#include<stdlib.h>

#include"bst.h"

int searchSteps;

/* Initialize BST node */
Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
}

/* Print values of BST in order using recursion */
void inorder(Node* root){
    /* Check if root of BST exist */
    if (root != NULL){ 
        Node* leftNode = root->left;
        Node* rightNode = root->right;

        if (leftNode != NULL){
            inorder(leftNode);
        }
        printf("%d->", root->data);

        if(rightNode != NULL){
            inorder(rightNode);
        }
    }else{
        printf("BST is empty, or not initialized");
    }
}

/* Insert new node by traversing with recursion */
Node* insert(Node* root, int data){

    /* Base Case, creating node when reached suitable position*/
    if (root == NULL){
        return createNode(data);
    } 

    if (data < root->data){
        root->left  = insert(root->left, data); 
    }
    /* Used "else if" instead "else" to avoid insertion of duplicate values */
    else if (data > root->data){
        root->right = insert(root->right, data);    
    }
    return root; 
} 

Node* searchRec(Node* root, int data){
    if (root == NULL || root->data == data){
        return root;
    }else if (root->data < data){
        searchSteps++;
        return searchRec(root->right, data);
    }else{
        searchSteps++;
        return searchRec(root->left, data);
    }
}

int search(Node* root, int data){
    searchSteps = 0;
    /* Return -1 if not found else return num of steps */
    if(searchRec(root, data) == NULL){
        return -1;
    }else{
        return searchSteps;
    }
}

Node* minValueNode(Node* node){
    Node* target = node;
    /* Go to the left child until reach leftmost */
    while (target && target->left != NULL) 
        target = target->left; 
  
    return target; 
}

Node* deleteNode(Node* root, int data){
    /* Base case */ 
    if (root == NULL){ 
        return root; 
    }
    /* Go left if smaller than root's val*/
    if (data < root->data){
        root->left = deleteNode(root->left, data); 
    }
    /* Go right if bigger than root's val*/
    else if (data > root->data){
        root->right = deleteNode(root->right, data); 
    }
    /* If they are equal this is the node to delete */
    else{ 
        Node* tmp;
        /* No child or one child */
        if (root->left == NULL){ 
            tmp = root->right; 
            free(root); 
            return tmp; 

        }else if (root->right == NULL){ 
            tmp = root->left; 
            free(root); 
            return tmp; 
        } 
        /* Has two child, get the smallest one on right subtree (the closest val) */
        tmp = minValueNode(root->right); 
        root->data = tmp->data; // copied its value
        root->right = deleteNode(root->right, tmp->data); // then deleted it
    } 
    return root; 
}