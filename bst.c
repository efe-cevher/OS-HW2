#include"bst.h"

int searchSteps;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
}

void inorder(Node* root){
    if (root != NULL){ 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
}

Node* insert(Node* root, int data){
    /* If the tree is empty, return a new node */
    if (root == NULL){
        return createNode(data);
    } 
    /* Otherwise, recur down the tree */
    if (data < root->data){
        root->left  = insert(root->left, data); 
    }
    else if (data > root->data){
        root->right = insert(root->right, data);    
    }
    /* return the (unchanged) node pointer */
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
    if(searchRec(root, data) == NULL){
        return -1;
    }else{
        return searchSteps;
    }
}

Node* minValueNode(Node* node){
    Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
}

Node* deleteNode(Node* root, int data){
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (data < root->data) 
        root->left = deleteNode(root->left, data); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (data > root->data) 
        root->right = deleteNode(root->right, data); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        Node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
}


