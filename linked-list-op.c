#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}node;

void print(node *head) {
    node *n = head;
    while (n) {
        printf("%d ", n->val);
        n = n->next;
    }
}

void reverse(node *head, node **newhead) {
    if (!head) return;
    if (head->next == NULL) {
        *newhead = head;
        return;
    }
    reverse(head->next, newhead);
    head->next->next = head;
    head->next = NULL;
}

void insert_n(node **head, int num) {
    node *n = malloc(sizeof(node));
    n->val = num;
    n->next = NULL;
    node **cur = head; 
    while (*cur && (*cur)->val < n->val ) {
        cur = &((*cur)->next);
    }
    n->next = *cur;
    if(*cur != *head) *cur = n;
    else *head = n;
}

void remove_n(node **head, int num) {
    node **cur = head;
    while (*cur && (*cur)->val != num) {
        cur = &((*cur)->next);
    }
    node *del_n = *cur;
    if(*cur != *head && *cur) *cur = (*cur)->next;
    else *head = (*head)->next;
}

int main()
{
    node *head = (node[]){1, (node[]){2, (node[]){3, (node[]){5, NULL}}}}; // 1 2 3 5
    /*
    node *newhead = head;
    reverse(head, &newhead);
    head = newhead; 
    */

    insert_n(&head, 5);
    
    remove_n(&head, 4);
    
    print(head);

    return 0;
}
