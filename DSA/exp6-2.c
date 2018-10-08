#include <stdio.h>
#include <stdlib.h>

#define LIM 20

struct LinkedList {
    struct Node {
        int data;
        struct Node *next;
    } *head;
};

void init(struct LinkedList *LL) {
    LL->head = NULL;
}

void push(struct LinkedList *LL, int info) {
    if (LL->head == NULL) {
        LL->head = malloc(sizeof(struct Node));
        LL->head->data = info;
        LL->head->next = NULL;
    } else {
        struct Node *temp = LL->head;
        struct Node *new  = malloc(sizeof(struct Node));
        new->data = info;
        new->next = NULL;

        while (temp->next!=NULL)
            temp = temp->next;
        temp->next = new;
    }
}

int pop(struct LinkedList *LL) {
    if (LL->head == NULL) {
        printf("Underflow Error!");
        return '\0';
    } else if (LL->head->next == NULL) {
        int ans = LL->head->data;
        free(LL->head);
        LL->head = NULL;
        return ans;
    } else {
        int ans;
        struct Node *temp = LL->head;
        while (temp->next->next != NULL)
            temp = temp->next;
        ans = temp->next->data;
        free(temp->next);
        temp->next = NULL;
        return ans;
    }
}

int isDigit(char ch) {
    return (ch>='0' && ch<='9')?1:0;
}

int main() {
    char postfix[LIM];
    printf("Enter Postfix expresssion:\n");
    scanf("%s", postfix);

    struct LinkedList Stack;
    init(&Stack);

    int i;
    for (i=0; postfix[i]!='\0'; i++) {
        if (isDigit(postfix[i])) {
            push(&Stack, postfix[i]-'0');
        }
        else {
            int b = pop(&Stack);
            int a = pop(&Stack);
            printf("%d%c%d\n", a, postfix[i], b);
            switch (postfix[i]) {
                case '+':
                    push(&Stack, a+b);
                    break;
                case '-':
                    push(&Stack, a-b);
                    break;
                case '*':
                    push(&Stack, a*b);
                    break;
                case '/':
                    push(&Stack, a/b);
                    break;
                default:
                    printf("Unknown operator %c\n", postfix[i]);
                    return 1;
            }
        }
    }

    printf("The answer is %d\n", pop(&Stack));
    return 0;
}