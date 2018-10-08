#include <stdio.h>
#include <stdlib.h>

#define LEN 20

struct LinkedList {
    struct Node {
        char data;
        struct Node *next;
    } *head;
};

void init(struct LinkedList *LL) {
    LL->head = NULL;
}

void push(struct LinkedList *LL, char info) {
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

char pop(struct LinkedList *LL) {
    if (LL->head == NULL) {
        printf("Underflow Error!");
        return '\0';
    } else if (LL->head->next == NULL) {
        char ans = LL->head->data;
        free(LL->head);
        LL->head = NULL;
        return ans;
    } else {
        char ans;
        struct Node *temp = LL->head;
        while (temp->next->next != NULL)
            temp = temp->next;
        ans = temp->next->data;
        free(temp->next);
        temp->next = NULL;
        return ans;
    }
}

char peek(struct LinkedList *LL) {
    if (LL->head == NULL) {
        printf("Underflow Error!");
        return '\0';
    } else if (LL->head->next == NULL) {
        char ans = LL->head->data;
        return ans;
    } else {
        char ans;
        struct Node *temp = LL->head;
        while (temp->next->next != NULL)
            temp = temp->next;
        ans = temp->next->data;
        return ans;
    }
}

int isEmpty(struct LinkedList *LL) {
    return (LL->head == NULL)?1:0;
}

void display(struct LinkedList *LL) {
    if (LL->head != NULL) {
        struct Node *temp = LL->head;
        while(temp->next != NULL) {
            printf("%c", temp->data);
            temp = temp->next;
        }
        printf("%c", temp->data);
    }
    printf("\t");
}

void arr_display_stack(char *arr, int top) {
    int i;
    for( i=0; i<=top; i++ ) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

int openbrace( char ch ) {
    switch (ch) {
        case '(': case '{': case '[': case '<':
            return 1;
        default:
            return 0;
    }
}

int closebrace( char ch ) {
    switch (ch) {
        case ')': case '}': case ']': case '>':
            return 1;
        default:
            return 0;
    }
}

int matchbrace( char open, char close ) {
         if (open=='{' && close=='}') return 1;
    else if (open=='(' && close==')') return 1;
    else if (open=='[' && close==']') return 1;
    else if (open=='<' && close=='>') return 1;
    else return 0;
}

int operator( char ch ) {
    switch (ch) {
        case '+': case '-': case '/': case '*': case '^':
            return 1;
        default:
            return 0;
    }
}

int precedence( char ch ) {
    switch (ch) {
        case '^': return 4;
        case '*': case '/': return 3;
        case '+': case '-': return 2;
        default: return 0;
    }
}

int main() {
    char infix[LEN];
    char postfix[LEN];
    int curr = -1;

    struct LinkedList Stack;
    init(&Stack);

    printf("Enter the in-fix expression:\n");
    scanf( "%s", &infix );
    printf("Scanned\tStack\tPostfix Expression\n");

    int i;
    for (i=0; infix[i]!='\0'; i++) {
        if (openbrace( infix[i] )) {
            push(&Stack, infix[i]);
        } else if (operator( infix[i] )) {
            if( precedence( peek( &Stack ) ) > precedence( infix[i] )) {
                postfix[++curr] = pop( &Stack );
            }
            push( &Stack, infix[i] );
        } else if (closebrace( infix[i] )) {
            while (!matchbrace( peek( &Stack ), infix[i] )) {
                postfix[++curr] = pop( &Stack );
            }
            pop( &Stack ); // Remove opening brace without pushing to postfix
        } else {
            postfix[++curr] = infix[i];
        }
        printf("%c\t", infix[i]);
        display(&Stack);
        arr_display_stack(postfix, curr);
    }

    while (!isEmpty( &Stack )) {
        postfix[++curr] = pop( &Stack );
        printf("%c\t", infix[i]);
        display(&Stack);
        arr_display_stack(postfix, curr);
    }

    postfix[++curr] = '\0';

    printf("The postfix equivalent is:\n%s\n", postfix);

    return 0;
}