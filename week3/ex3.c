#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}node;


void print_list(node* lst);
void insert_first(node** lst, int val);
void insert_node(node** lst, int i, int val);
void delete_node(node** lst, int i);

int main(){
    node* list = NULL;
    node* first = (node*)malloc(sizeof(node));
    node* sec = (node*)malloc(sizeof(node));
    node* third = (node*)malloc(sizeof(node));
    
    insert_first(&list, 111);
    insert_first(&list, 222);
    insert_first(&list, 333);
    print_list(list);    
    printf("\n");
    insert_node(&list, 3, 123);
    print_list(list);
    printf("\n");
    insert_node(&list, 0, 456);
    print_list(list);
    printf("\n");
    insert_node(&list, 7, 789);
    print_list(list);
    printf("\n");

    delete_node(&list, 3);
    print_list(list);
    printf("\n");
    delete_node(&list, 0);
    print_list(list);
    printf("\n");
    delete_node(&list, 8);
    print_list(list);
    printf("\n");
}

void print_list(node* head){
    while(head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }    
}

/* Inserts a new node with value <val> into the first position in list*/
void insert_first(node** lst, int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = *lst;
    *lst = newNode;
}

/** Inserts a new node with value <val> at position <index> in the list
 * Returns if index is greater than list length
*/
void insert_node(node** lst, int index, int val){
    if(index == 0){
        insert_first(lst, val);
        return;
    }
    int j = 0;
    node* current = *lst;
    while(j != index - 1){
        j++;
        current = current->next;
        if(current == NULL)
            return;
    }
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = current->next;
    current->next = newNode;
}

/** Deletes a node at index <index> in the list <lst>
 * Returns if the index is greater (or equal) than list length
 */
void delete_node(node** lst, int index){
    if (*lst == NULL)
        return;
    node* current = *lst;
    if (index == 0){
        *lst = current->next; // change head
        free(current);
        return;
    }
    int j = 0;
    while (j != index - 1){
        j++;
        current = current->next;
        if (current == NULL)
            return;
    }
    if (current->next == NULL)  
        return;  // if index for deletion is greater than the list length
    // save the pointer to the element after element to be deleted
    node* next = current->next->next;  
    free(current->next);
    current->next = next;
}