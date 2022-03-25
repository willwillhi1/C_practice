#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int value;
    struct stack *next;
} stack;

int Isempty(stack *head) {
    if (head == NULL) return 1;
    else return 0;
}

void push(int value, stack **head) {
    stack *new = malloc(sizeof(stack));
    new->value = value;
    new->next = NULL;
    
    if (Isempty(*head)) {
        *head = new;
    }
    else {
        new->next = *head;
        *head = new;
    }
}

void pop(stack **head){
    if (Isempty(*head)) {
        printf("stack is empty!\n");
        return;
    }
    stack *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void print(stack *head) {
    stack *now = head;
    while(now != NULL) {
        printf("%d ", now->value);
        now = now->next;
    }
    printf("\n");
}

int main()
{
    stack *head = malloc(sizeof(stack));
    printf("Push:1,2,3,4,5:\n");
    push(1, &head);
    push(2, &head);
    push(3, &head);
    push(4, &head);
    push(5, &head);
    print(head);
    printf("First time pop\n");
    pop(&head);
    print(head);
    printf("Second time pop\n");
    pop(&head);
    print(head);
    return 0;
}
