#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"stack.h"
#include"bst.h"

/* Return random value in given range */
int randr(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int main(){

    int arr[] = { 30, 70, 40, 80, 20, 60 }; //demo array

    Node* root = createNode(50); // created bst by creating its root node
    
    int n = (int) sizeof(arr)/sizeof(arr[0]); //size of array

    for(int i=0; i < n; i++){
        insert(root, arr[i]); //inserted demo items to bst
    }

    printf("Initial tree\n");
    inorder(root); //print initial tree
    printf("\n");

    srand(time(NULL)); // initialization for random

    Stack* taskStack = createStack(10);

    /* Loop 10 times random tasks*/
    for(int i=0; i<10; i++){
        int r = randr(1,4);
        int val;

        /* Switch case for 4 different task*/
        switch(r){
        case 1: // insert to bst
        {
            val = randr(0,30) * 5; // random insertions
            printf("\ntask->insert:%d", val);
            insert(root, val);
            printf("\nthe value:%d is inserted\n", val);
            inorder(root);

            push(taskStack, 1, val); // push task and its val to stack
            break;
        }

        case 2: // delete from bst
        {   
            /* Get delete val from demo arr randomly */
            int i,c;
            i = randr(0,n-1);
            val = arr[i];
            for (int c = i; c < n - 1; c++){
                arr[c] = arr[c+1];
            }
            n--;

            printf("\ntask->delete:%d", val);
            deleteNode(root, val);
            printf("\nthe value:%d is deleted\n", val);
            inorder(root);

            push(taskStack, 2, val);
            break;
        }
        case 3: // print min value
        {
            Node* min = minValueNode(root);
            printf("\ntask->min\nminval %d is found", min->data);
            break;
        }
        case 4: // search for a value
        {
            int i = randr(0,15)*10;
            printf("\ntask->search:%d", i);
            int res = search(root, i);
            if(res == -1){
                printf("\nsearched %d is not found\n", i);
            }else{
                printf("\nsearched %d is found in %d steps", i, res);
            }
            break;
        }
        default:
            break;
        }
        printf("\n");
    }

    /* Reverse Modifications */

    /* User input */
    int userIn;
    printf("\nHow many steps back: ");
    scanf(" %d", &userIn);

    int counter = 0;
    /* Run until stack is empty or counter reached user input */
    while (isEmpty(taskStack) == 0 && counter<userIn){
        /* Get task and its value */
        int task = taskStack->task[taskStack->top];
        int val = taskStack->values[taskStack->top];

        /* Execute tasks by reversing them */
        if(task == 1){
            printf("\ntask->delete:%d", val);
            deleteNode(root, val);
            printf("\nthe value:%d is deleted\n", val); 
        }else{
            printf("\ntask->insert:%d", val);
            insert(root, val);
            printf("\nthe value:%d is inserted\n", val);
        }
        inorder(root);
        printf("\n");

        pop(taskStack); // finally remove top task and value
        counter++;
    }
    /* Inform user stack reverse modifications reached end 
        because there are no tasks left in stack */
    if(isEmpty(taskStack)){
        printf("\nThere is no task left to be undone.\n");
    }
}