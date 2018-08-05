#define NULL 0

struct Linked_List
{
    int data;
    struct Linked_List * next;
};

void printll(struct Linked_List * ll)
{
    if(ll == NULL)
        return;
    // end if

    printf("%d ", ll->data);

    // Check if
    // next node is NULL
    // next node is last node
    if (ll->next == NULL)
        return;
    else if (ll->next->next == NULL);
        return;
    // end if

    printll(ll->next->next);
}