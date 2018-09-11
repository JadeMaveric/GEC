/* Implement stack using array
 * Implement queue using array
 * Implement stack using LL
 * Implement queue using LL
 * */
#include <stdio.h>
#include <stdlib.h>
#define MAX 4

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

int *arr_push_stack(int *arr, int *top, int data) {
    if( *top == MAX-1 ) printf("Overflow error!\n");
    else arr[++(*top)] = data;
    return arr;
}

int *arr_push_queue(int *arr, int *front, int *rear, int data) {
    if( *front == -1 ) arr[*front=*rear=0] = data;
    else if( *rear == MAX-1 ) printf("Overflow error!\n");
    else arr[++(*rear)] = data;
    return arr;
}

int pop(struct LinkedList *LL) {
    if (LL->head == NULL) {
        printf("Underflow Error!");
        return -1;
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

int arr_pop(int *arr, int *top) {
    if( *top == -1 ) {
        printf("Underflow error!\n");
        return 0;
    }
    else return arr[(*top)--];
}

int delete(struct LinkedList *LL) {
    if (LL->head == NULL) {
        printf("Underflow error!");
        return -1;
    } else if (LL->head->next == NULL) {
        int ans = LL->head->data;
        free(LL->head);
        LL->head = NULL;
        return ans;
    } else {
        int ans = LL->head->data;
        struct Node *temp = LL->head->next;
        free(LL->head);
        LL->head = temp;
        return ans;
    }
}

int arr_delete(int *arr, int *front, int *rear) {
    if( *front == -1 ) {
        printf("Underflow error!\n");
        return 0;
    }
    
    else {
        (*front)++;
        int temp = arr[*front-1];
        if( *front > *rear)
            *front = *rear = -1;
        return temp;
    }
}

int peek_stack(struct LinkedList *LL) {
    if (LL->head == NULL) {
        return -1;
    } else {
        return LL->head->data;
    }
}

int arr_peek_stack(int *arr, int top) {
    if( top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    
    else {
        return arr[top];
    }
}

int peek_queue(struct LinkedList *LL) {
    if (LL->head == NULL) {
        return -1;
    } else {
        struct Node *temp = LL->head;
        while (temp->next != NULL)
            temp = temp->next;
        return temp->data;
    }
}

int arr_peek_queue(int *arr, int front) {
    if( front == -1) {
        printf("Queue is empty\n");
    }

    else {
        return arr[front];
    }
}

int isEmpty(struct LinkedList *LL) {
    return (LL->head == NULL)?1:0;
}

int arr_isEmpty_stack(int *arr, int top) {
    return top==-1;
}

int arr_isEmpty_queue(int *arr, int front, int rear) {
    return (front==rear)&&(front==-1);
}

void display(struct LinkedList *LL) {
    if (LL->head != NULL) {
        struct Node *temp = LL->head;
        while(temp->next != NULL) {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("%d-->", temp->data);
    }
    printf("NULL\n");
}

void arr_display_stack(int *arr, int top) {
    if( top == -1 ) {
        printf("Empty\n");
    }
    else {
        int i;
        for( i=0; i<=top; i++ ) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void arr_display_queue(int *arr, int front, int rear) {
    if( front == -1) {
        printf("Empty\n");
    }
    else {
        int i;
        for( i=front; i<=rear; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int userInput;
    int val;
    
    struct LinkedList A;
    init(&A);

    int X[MAX];
    int front=-1, rear=-1, top=-1;

    printf("1. Stack using Linked List\n");
    printf("2. Queue using Linked List\n");
    printf("3. Stack using Array\n");
    printf("4. Queue using Array\n");
    printf(">");
    scanf("%d", &userInput);

    switch (userInput) {
    case 1:
        userInput = 0;
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Is Empty?\n");
        printf("4. Display\n");
        printf("5. Peek\n");
        printf("0. Quit\n");
        printf(">");
        do {
            printf(">");
            scanf("%d", &userInput);
            
            switch (userInput) {
            case 1:
                printf("Push: ");
                scanf("%d", &val);
                push(&A, val);
                break;
            case 2:
                printf("Pop: %d\n", pop(&A));
                break;
            case 3:
                printf(isEmpty(&A)?"Yes\n":"No\n");
                break;
            case 4:
                display(&A);
                break;
            case 5:
                printf("Peek: %d\n", peek_stack(&A));
                break;
            case 0:
                break;
            default:
                printf("Invalid Option\n");
            }
        } while (userInput != 0);
        break;
    case 2:
        userInput = 0;
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Is Empty?\n");
        printf("4. Display\n");
        printf("5. Peek\n");
        printf("0. Quit\n");
        printf(">");
        do {
            printf(">");
            scanf("%d", &userInput);
            
            switch (userInput) {
            case 1:
                printf("Insert: ");
                scanf("%d", &val);
                push(&A, val);
                break;
            case 2:
                printf("Delete: %d\n", delete(&A));
                break;
            case 3:
                printf(isEmpty(&A)?"Yes\n":"No\n");
                break;
            case 4:
                display(&A);
                break;
            case 5:
                printf("Peek: %d\n", peek_queue(&A));
                break;
            case 0:
                break;
            default:
                printf("Invalid Option\n");
            }
        } while (userInput != 0);
        break;
    case 3:
        userInput = 0;
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Is Empty?\n");
        printf("4. Display\n");
        printf("5. Peek\n");
        printf("0. Quit\n");
        printf(">");
        do {
            printf(">");
            scanf("%d", &userInput);
            
            switch (userInput) {
            case 1:
                printf("Push: ");
                scanf("%d", &val);
                arr_push_stack(X, &top, val);
                break;
            case 2:
                printf("Pop: %d\n", arr_pop(X, &top));
                break;
            case 3:
                printf(arr_isEmpty_stack(X, top)?"Yes\n":"No\n");
                break;
            case 4:
                arr_display_stack(X, top);
                break;
            case 5:
                printf("Peek: %d\n", arr_peek_stack(X, top));
                break;
            case 0:
                break;
            default:
                printf("Invalid Option\n");
            }
        } while (userInput != 0);
        break;
    case 4:
        userInput = 0;
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Is Empty?\n");
        printf("4. Display\n");
        printf("5. Peek\n");
        printf("0. Quit\n");
        printf(">");
        do {
            printf(">");
            scanf("%d", &userInput);
            
            switch (userInput) {
            case 1:
                printf("Insert: ");
                scanf("%d", &val);
                arr_push_queue(X, &front, &rear, val);
                break;
            case 2:
                printf("Delete: %d\n", arr_delete(X, &front, &rear));
                break;
            case 3:
                printf(arr_isEmpty_queue(X, front, rear)?"Yes\n":"No\n");
                break;
            case 4:
                arr_display_queue(X, front, rear);
                break;
            case 5:
                printf("Peek: %d\n", arr_peek_queue(X, front));
                break;
            case 0:
                break;
            default:
                printf("Invalid Option\n");
            }
        } while (userInput != 0);
        break;
    }
}