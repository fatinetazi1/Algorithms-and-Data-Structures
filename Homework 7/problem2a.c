/*
Explanation: 
The reverse function is an in-situ algorithm because 
it does not require additional memory to reverse the list. 
*/

#include<stdio.h>
#include<stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};
 
// Reverse linked list function
static void reverse(struct StackNode** head) {
    struct StackNode* prev = NULL;
    struct StackNode* cur = *head;
    struct StackNode* next = NULL;

    while (cur != NULL) {
        next = cur->next;  
        cur->next = prev;   
        prev = cur;
        cur = next;
    }

    *head = prev;
}
 
// Pushing a new element function
void push(struct StackNode** head, int newelem) {
    struct StackNode* newnode = (struct StackNode*) malloc(sizeof(struct StackNode));
    newnode->data = newelem;
    newnode->next = (*head);    
    (*head) = newnode;
}
 
// Printing the list function
void print(struct StackNode *head) {
    struct StackNode *temp = head;
    while(temp != NULL) {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
}    

int main() {
    struct StackNode* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3); 
    push(&head, 4);   
    push(&head, 5);     
     
    printf("List: \n");
    print(head);    
    reverse(&head);   

    printf("\nReversed List \n");
    print(head);   
    printf("\n"); 

     return 0;
}