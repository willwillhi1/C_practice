#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

struct node {
    int data;
    struct node *next, *prev;
};

void insert(struct node** head, int value)
{
    struct node* n = malloc(sizeof(struct node));
    n->data = value;
    if (*head == NULL) {
        n->next = n;
        n->prev = n;
        *head = n;
    }
    else {
        n->next = *head;
        (*head)->prev->next = n;
        n->prev = (*head)->prev;
        (*head)->prev = n;
    }
}

void print_list(struct node* head)
{
    struct node* n = head;
    do {
        printf("%d->", n->data);
        n = n->next;
    } while (head != n);
    printf("\n");
}

struct node* merge2list(struct node* head1, struct node* head2)
{
    struct node* head = NULL;
    struct node** cur = &head;
    struct node* cur1 = head1;
    struct node* cur2 = head2;
    struct node* last1 = head1->prev;
    struct node* last2 = head2->prev;
    while ((*cur) != head1 && (*cur) != head2) {
        struct node** tmp = (cur1->data < cur2->data) ? &cur1 : &cur2;
        *cur = *tmp;
        // 如果是兩個 linked-list 都還沒變就直接把 prev 指向自己
        (*tmp)->prev = (cur1 != head1 || cur2 != head2) \
                       ? (struct node*)container_of(*cur, struct node, next) \
                       : *tmp;
        *tmp = (*tmp)->next;
        cur = &((*cur)->next);
    } 
    // 此時 *cur 會指向已經跑完的 linked-list 的開頭，所以只要把另一個 linked-list 剩餘部分接上就好
    if (*cur == head2) {
        // 先把 *cur 指向 head，且 head->prev 指向 *cur 本身這個點，先完成整個 circular linked-list 結構
        *cur = head;
        head->prev = (struct node*)container_of(*cur, struct node, next);
        // 最後就把剩下的部分接起來就好
        *cur = cur1;
        cur1->prev = (struct node*)container_of(*cur, struct node, next);
        head->prev = last1;
        last1->next = head;
    }
    // 同上
    else if (*cur == head1) {
        *cur = head;
        head->prev = (struct node*)container_of(*cur, struct node, next);
        *cur = cur2;
        cur2->prev = (struct node*)container_of(*cur, struct node, next);
        head->prev = last2;
        last2->next = head;
    }
    return head;
}

struct node* merge_sort(struct node* head) 
{
    if (head == head->next) return head;
    
    struct node* p1 = head;
    struct node* p2 = head->prev;
    while (p1 != p2 && p1->next != p2) {
        p1 = p1->next;
        p2 = p2->prev;
    }
    // 把 linked-list 分成兩等分
    if (p1 == p2) p2 = p2->next;
    head->prev->next = p2;
    p2->prev = head->prev;
    head->prev = p1;
    p1->next = head;
    
    // 依序做 merge_sort，然後再把得到的兩個排序好的 linked-list 合併
    struct node* head1 = merge_sort(head);
    struct node* head2 = merge_sort(p2);
    return merge2list(head1, head2);
}

int main()
{
    struct node* head = NULL;
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 0);
    insert(&head, 5);
    
    print_list(head);
    head = merge_sort(head);
    print_list(head);
    return 0;
}
