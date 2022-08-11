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

node_t* mergesort(node_t *n)
{
    if (!n->next) return n;
    node_t *slow = n, *fast = n;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    node_t *R = mergesort(slow->next);
    slow->next = NULL;
    node_t *L = mergesort(n);
    
    node_t *cur = R;
    node_t *head = R;
    if (L->val < R->val) {
        head = L;
        cur = L;
        L = L->next;
    }
    else R = R->next;
    
    while (L && R) {
        if (L->val < R->val) {
            cur->next = L;
            L = L->next;
        }
        else {
            cur->next = R;
            R = R->next;
        }
        cur = cur->next;
    }
    if (L) cur->next = L;
    else cur->next = R;
    return head;
}


int main()
{
    node_t *head = (CON){2, (CON){5, (CON){4, 
    (CON){6, (CON){8, (CON){1, (CON){7, (CON){3, NULL}}}}}}}};
    
    //print(head);
    print(mergesort(head));

    return 0;
}
