#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

int findlength()
{
    if (head->next == NULL)
    {
        return 0;
    }
    struct node *ptr = head->next;
    int count = 1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}
void pushelements()
{
    if (findlength() > 5)
    {
        printf("Stack overflow");
        return;
    }
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head->next;
    int data;
    printf("\nEnter the element you want to enter: ");
    scanf("%d", &data);
    p->data = data;
    p->next = ptr;
    head->next = p;
}
void displaystack()
{
    if (head->next == NULL)
    {
        printf("Stack underflow");
        return;
    }
    struct node *ptr = head->next;
    printf("\nThe stack is: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void popelement()
{
    if (head->next == NULL)
    {
        printf("Stack underflow");
        return;
    }
    head = head->next;
    printf("Element popped");
}
void peakelement()
{
    if (head->next == NULL)
    {
        printf("Stack underflow");
        return;
    }
    printf("\nThe element at the top is: %d", head->next->data);
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    int n, ch, i, j, k;
    // printf("Enter the number of elements you want to enter in the stack: ");
    // scanf("%d", &n);
    // for (i = 0; i < n; i++)
    // {
    //     pushelements();
    // }
    while (1)
    {
        printf("\nMenu: ");
        printf("\n1.Push an element");
        printf("\n2.Pop an element");
        printf("\n3.Peek");
        printf("\n4.Display stack");
        printf("\n5.Find length");
        printf("\nYour choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            pushelements();
            break;
        case 2:
            popelement();
            break;
        case 3:
            peakelement();
            break;
        case 4:
            displaystack();
            break;
        case 5:
            printf("\nThe length of the stack is %d", findlength());
            break;
        default:
            printf("\nPlease enter a valid choice!");
            break;
        }
    }
}

