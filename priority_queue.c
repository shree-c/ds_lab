#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int priority;
    struct node *next;
} node;
node *newNode(int data, int priority, node *next)
{
    node *hold = (node *)malloc(sizeof(node));
    hold->data = data;
    hold->next = next;
    hold->priority = priority;
    return hold;
}
void display(node *start)
{
    if (start == NULL)
    {
        printf("list empty\n");
        return;
    }
    node *hold = start;
    while (hold != NULL)
    {
        printf("--> data: %d, priority: %d\n", hold->data, hold->priority);
        hold = hold->next;
    }
}
node *push(node *start, int val, int pri)
{
    if (start == NULL)
    {
        start = newNode(val, pri, NULL);
        return start;
    }
    if (start->priority < pri)
    {
        start = newNode(val, pri, start);
        printf("came here\n");
        return start;
    }
    node *temp = start;
    while (temp->next != NULL && temp->next->priority > pri)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        temp->next = newNode(val, pri, NULL);
    }
    else
    {
        temp->next = newNode(val, pri, temp->next);
    }
    return start;
}
node *pop(node *start)
{
    if (start == NULL)
    {
        printf("queue empty\n");
        return start;
    }
    printf("removed %d\n", start->data);
    node *temp = start;
    start = start->next;
    free(temp);
    return start;
}
int main()
{
    int opt = 0;
    node *start = NULL;
    do
    {
        printf("1. push\n2. pop\n3. display\n4. exit\n::");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        {
            printf("Enter a value: ");
            int val;
            scanf("%d", &val);
            printf("Enter priority: ");
            int pri;
            scanf("%d", &pri);
            start = push(start, val, pri);
            break;
        }
        case 2:
            start = pop(start);
            break;
        case 3:
            display(start);
            break;
        case 4:
            printf("byee\n");
            break;
        default:
            printf("invalid option\n");
            break;
        }
    } while (opt != 4);
    return 0;
}
