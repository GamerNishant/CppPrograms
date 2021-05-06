#include <stdio.h>
#include <stdlib.h>

//Node Structure

struct node
{
    int val;
    struct node *next;
} *ptr, *start, *cur, *pre, *temp;

// Building Ciruclar List

struct node *createNode(int a)
{
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->val = a;
    ptr->next = NULL;
    return ptr;
}

//Creating circular list asa input comes

void insert()
{
    int a;
    scanf("%d", &a);
    ptr = createNode(a);
    if (start == NULL)
    {
        start = ptr;
        ptr->next = ptr;
    }
    else
    {
        cur = start;
        while (cur->next != start)
            cur = cur->next;
        cur->next = ptr;
        ptr->next = start;
    }
}

//Displaying the list elements

void display()
{
    cur = start;
    if (cur == NULL)
        printf("Empty list.\n");
    else
    {
        printf("\nCurrent List: ");
        while (cur->next != start)
        {
            printf("%d, ", cur->val);
            cur = cur->next;
        }
        printf("%d\n\n", cur->val);
    }

}

//insertion in the beginning

void insertBegin()
{
    int a;
    printf("Enter element:");
    scanf("%d", &a);
    ptr = createNode(a);
    if (start == NULL)
    {
        start = ptr;
        ptr->next = ptr;
    }
    else
    {
        cur = start;
        while (cur->next != start)
            cur = cur->next;
        cur->next = ptr;
        ptr->next = start;
        start = ptr;
    }
}

//insertion at the end

void insertEnd()
{
    int a;
    printf("Enter Element:");
    scanf("%d", &a);
    ptr = createNode(a);
    if (start == NULL)
    {
        start = ptr;
        ptr->next = ptr;
    }
    else
    {
        cur = start;
        while (cur->next != start)
            cur = cur->next;
        cur->next = ptr;
        ptr->next = start;
    }
}

//insertion after a particular element

void insertRandom()
{
    int a,b;
    printf("Particular Element:");
    scanf("%d", &b);
    printf("Enter new element:");
    scanf("%d", &a);
    ptr = createNode(a);
    pre = start;
    cur = start->next;

    while (cur != start)
    {
        if (pre->val == b)
        {
            pre->next = ptr;
            ptr->next = cur;
            break;
        }
        pre = pre->next;
        cur = cur->next;
    }

    if (pre == start)
        printf("Element Not found.\n");
}

//Deleting first

void deleteBegin()
{
    if (start == NULL)
    {
        printf("Underflow.");
        return;
    }
    printf("First Deleted.\n");
    cur = start;
    if (start->next == cur)
    {
        free(cur);
        start = NULL;
        return;
    }

    temp = start;
    while (cur->next != start)
        cur = cur->next;
    cur->next = start->next;
    start = cur->next;
    free(temp);
}

//Deleting End

void deleteEnd()
{
    if (start == NULL)
    {
        printf("Underflow.");
        return;
    }
    printf("Last Deleted.\n");
    pre = start;
    if (start->next == start)
    {
        free(pre);
        start = NULL;
        return;
    }
    cur = start->next;
    while (cur != start && cur->next != start)
    {
        pre = pre->next;
        cur = cur->next;
    }
    if (cur == start)
    {
        free(cur);
        start = NULL;
    }
    else
    {
        pre->next = start;
        free(cur);
    }
}

// deletion of any element of list

void deleteRandom()
{
    int a;
    int notFound = 0;
    if (start == NULL)
    {
        printf("Underflow.");
        return;
    }
    printf("Enter element to delete:");
    scanf("%d", &a);
    pre = start;
    cur = start->next;
    if (cur == start && pre->val == a)
    {
        printf("\nSuccessfully Deleted.");
        free(pre);
        start = NULL;
        return;
    }
    while (cur != start)
    {
        if (cur->val == a)
        {
            pre->next = cur->next;
            free(cur);
            notFound = 1;
            break;
        }
        cur = cur->next;
        pre = pre->next;
    }
    if (notFound == 0)
        printf("Element Not Found.");
}

int main()
{
    int n;
    int i;
    int outCondn = 0;
    int ch;

    printf("Enter the size of list:");
    scanf("%d", &n);
    printf("Enter the list elements:");
    for (i = 0; i < n; i++)
    {
        insert();
    }

    display();


    printf("\n------ MENU -----");
    printf("\n1. Display List.\n");
    printf("2. Insert At End.\n");
    printf("3. Insert After Number.\n");
    printf("4. Insert At Head.\n");
    printf("5. Delete From End.\n");
    printf("6. Delete Particular Element.\n");
    printf("7. Delete From Head.\n");
    printf("8. Exit.\n");
    printf("---- END ----\n\n");

    while (outCondn == 0)
    {
        printf("Enter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertRandom();
            break;
        case 4:
            insertBegin();
            break;
        case 5:
            deleteBegin();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deleteRandom();
            break;
        case 8:
            outCondn = 1;
            break;
        default:
            printf("Jyada tej mt ho");
            break;
        }
    }
    return 0;
}