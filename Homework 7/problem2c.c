#include<stdio.h>
#include<stdlib.h>
 
struct LNode {
    int data;
    struct LNode *next;
};
 
struct TNode {
    int data;
    struct TNode *left;
    struct TNode *right;
};

// Allocates a new node with the given data and 
// NULLs left and right pointers function
struct TNode* newNode(int data) {
    struct TNode* node = (struct TNode*) malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
 
// Count of nodes in a linked list function
int countLNodes(struct LNode *head) {
    int count = 0;
    struct LNode *temp = head;
    while(temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

// Constructs balanced BST and returns root of it.
struct TNode* constBST(struct LNode **head, int n) {
    if (n <= 0) {
        return NULL;
    }

    struct TNode *left = constBST(head, n/2);
    struct TNode *root = newNode((*head)->data);
    root->left = left;
    *head = (*head)->next;
    root->right = constBST(head, n-n/2-1);

    return root;
}
 
// Counts the number of nodes in linked list and then calls
// constBST() to construct BST 
struct TNode* sortedListToBST(struct LNode *head) {
    int n = countLNodes(head);
    return constBST(&head, n);
}

 
// Insert a node at the beginging of the linked list function
void push(struct LNode** head, int newelem) {
    struct LNode* new_node = (struct LNode*) malloc(sizeof(struct LNode));
    new_node->data = newelem;
    new_node->next = (*head);
    (*head) = new_node;
}
 
// Print List function
void printL(struct LNode *node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
// Print Binary Tree function
void printT(struct TNode* node) {
    if (node == NULL){
        return;
    }
    printf("%d ", node->data);
    printT(node->left);
    printT(node->right);
}

int main() { 
    struct LNode* head = NULL;
 
    push(&head, 71);
    push(&head, 62);
    push(&head, 53);
    push(&head, 44);
    push(&head, 35);
    push(&head, 26);
    push(&head, 17);
 
    printf("List: \n");
    printL(head);
 
    struct TNode *root = sortedListToBST(head);

    printf("\nBinary Tree: \n");
    printT(root);
 
    return 0;
}