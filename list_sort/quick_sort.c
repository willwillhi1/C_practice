// reference https://hackmd.io/@sysprog/c-linked-list#Quick-sort-%E9%81%9E%E8%BF%B4%E7%89%88%E6%9C%AC
#include <stdio.h>
#define CON node_t[]
typedef struct ListNode {
    int val;
    struct ListNode *next;
}node_t;

void print(node_t *n)
{
    while (n) {
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");
}

node_t *quicksort(node_t *head) 
{
    if (!head || !head->next) return head;
    node_t *pivot = head;
    int pivot_val = pivot->val;
    node_t **cur = &(pivot->next);
    node_t *less_head = NULL;
    node_t **less_cur = &less_head;
    node_t *greater_head = NULL;
    node_t **greater_cur = &greater_head;
    while (*cur) {
        if ((*cur)->val <= pivot_val) {
            *less_cur = *cur;
            *cur = (*cur)->next;
            less_cur = &(*less_cur)->next;
            *less_cur = NULL;
        }
        else {
            *greater_cur = *cur;
            *cur = (*cur)->next;
            greater_cur = &(*greater_cur)->next;
            *greater_cur = NULL;
        }
    }
    less_head = quicksort(less_head);
    greater_head = quicksort(greater_head);
    node_t *ret = less_head ? less_head : pivot;
    if (less_head) {
        node_t *tmp;
        for (tmp = less_head; tmp->next;) tmp = tmp->next;
        tmp->next = pivot;
    }
    pivot->next = greater_head;
    return ret;
}

int main()
{
    node_t *head = (CON){2, (CON){5, (CON){4, 
    (CON){6, (CON){8, (CON){1, (CON){7, (CON){3, NULL}}}}}}}};
    
    //print(head);
    print(quicksort(head));

    return 0;
}
