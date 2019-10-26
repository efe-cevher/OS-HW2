#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"stack.h"
#include"bst.h"


int randr(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void printBST(Node* root){

    Node* leftNode = root->left;
    Node* rightNode = root->right;
    if (leftNode != NULL){
        printBST(leftNode);
    }

    printf("%d->", root->data);

    if(rightNode != NULL){
        printBST(rightNode);
    }

}

int main(){

    int arr[] = { 30, 70, 40, 80, 20, 60 };

    Node* root = createNode(50);
    
    int n = (int) sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i < n; i++){
        insert(root, arr[i]);
    }

    printf("Initial tree\n");
    printBST(root);
    printf("\n");

    srand(time(NULL)); // Initialization, should only be called once.

    Stack* taskStack = createStack(10);
    int stackItemCount = 0;

    for(int i=0; i<10; i++){
        int r = randr(1,4);
        int val, t;

        switch(r){
        case 1:
        {
            t = 1;
            val = randr(0,150);

            printf("\ntask->insert:%d\n", val);
            insert(root, val);
            printBST(root);
            printf("\n");

            stackItemCount++;
            push(taskStack, t, val);
            break;
        }

        case 2:
        {   
            t = 2;
            int i,c;
            i = randr(0,n-1);
            val = arr[i];
            for (int c = i; c < n - 1; c++){
                arr[c] = arr[c+1];
            }
            
            n--;

            printf("\ntask->delete:%d\n", val);
            deleteNode(root, val);
            printBST(root);
            printf("\n");

            stackItemCount++;
            push(taskStack, t, val);
            break;
        }
        case 3:
        {
            Node* min = minValueNode(root);
            printf("\ntask->min\nminval %d is found\n", min->data);
            break;
        }
        case 4:
        {
            int i = randr(0,150);
            printf("\ntask->search:%d", i);
            int res = search(root, i);
            if(res == -1){
                printf("\nsearched %d is not found\n", i);
            }else{
                printf("\nsearched %d is found in %d steps\n", i, res);
            }
            break;
        }
        default:
            break;
        }
        
    }

    int userIn;
    printf("\nHow many steps back: ");
    scanf(" %d", &userIn);

    if(userIn > stackItemCount){
        userIn = stackItemCount;
    }

    for(int i=0; i<userIn; i++){

        int task = taskStack->task[taskStack->top];
        int val = taskStack->values[taskStack->top];

        printf("task = %d", task);

        if(task == 1){
            printf("\ntask->delete:%d\n", val);
            deleteNode(root, val);
            printBST(root);
            printf("\n");
        }else{
            printf("\ntask->insert:%d\n", val);
            insert(root, val);
            printBST(root);
            printf("\n");
        }
        pop(taskStack);
    }
    if(isEmpty(taskStack) != 0){
        printf("There is no task left to be undone.\n");
    }
    

}


