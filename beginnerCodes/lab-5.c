/*

Write a program to display, insert and delete elements to a circular linked list using menu driven program.
Upload link: https://docs.google.com/forms/d/e/1FAIpQLScCSJh0Qq0c5nOkrj1dIZQjHjXW50fBcBCjUpJn-VufbXwmIg/viewform?usp=sf_link
G3: Fri Sep 4 10 pm
Class comments

Well Hello there,
Below are some of the awesome looking fonts.
Are you ready.

*/

#include <stdio.h>
#include <stdlib.h>

//Create a Circular linked list

struct node
{
    int data;
    struct node *next;
} * head;

//Create node

struct node *createNode()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    return newnode;
}

//creating Circular list

void createList()
{
    int data;
    struct node* ptr , *cur;
    scanf("%d", &data);
    ptr = createNode();
    ptr->data = data;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = ptr;
    }
    else
    {
        cur = head;
        while (cur->next != head)
            cur = cur->next;
        cur->next = ptr;
        ptr->next = head;
    }

}

//Display list

void displayList()
{
    struct node *travel = head;
    printf("\n");
    while (travel->next != head)
    {
        printf("%d, ", travel->data);
        travel = travel->next;
    }

    printf("%d" , travel->data);
    printf("\n\n");

}

//Insertion in list

void insertBegin()
{
    int data;
    struct node *newnode, *temp = head;

    printf("Enter Element:");
    scanf("%d", &data);

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = temp;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    head = newnode;
}

void insertEnd()
{
    int data;
    struct node *newnode, *temp = head;
    newnode = createNode();
    printf("Enter Element:");
    scanf("%d", &data);
    newnode->data = data;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;

    printf("\n");
}

void insertRandom()
{
    int particular;
    int data;
    struct node *newnode, *temp = head;
    newnode = createNode();

    printf("Enter Particular:");
    scanf("%d", &particular);
    printf("Enter Element:");
    scanf("%d", &data);

    newnode->data = data;

    while (temp->data != particular)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteBegin()
{
    struct node *temp = head;
    struct node *tail = head;

    if (head == NULL)
    {
        printf("Underflow.");
    }

    else
    {
        if(temp->next == head)
        {
            free(temp);
            return;
        }

        while(tail->next != head)
        tail = tail->next;

        tail->next = temp->next;

        head = tail->next;

        free(temp);
    }
}

void deleteEnd()
{
    struct node *pre = head, *delnode , *temp = head->next;

    if (head == NULL)
    {
        printf("Underflow.");
    }

    else
    {
        while (temp->next != head)
        {
            pre = pre->next;
            temp = temp->next;
        }
        delnode = pre->next;

        pre->next = temp->next;

        free(delnode);
    }
}

void deleteRandom()
{
    struct node *delnode, *temp = head;
    int data;

    printf("Enter Element:");
    scanf("%d", &data);

    while (temp->next->data != data)
    {
        temp = temp->next;
    }

    delnode = temp->next;
    temp->next = temp->next->next;

    free(delnode);
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
         createList();
     }

    displayList();

    printf("\n------ MENU -----");
    printf("\n1. Display List.\n");
    printf("2. Insert At End.\n");
    printf("3. Insert After Number.\n");
    printf("4. Insert At Head.\n");
    printf("5. Delete From Head.\n");
    printf("6. Delete From End.\n");
    printf("7. Delete Particular Element.\n");
    printf("8. Exit.\n");
    printf("---- END ----\n\n");

    while (outCondn == 0)
    {
        printf("Enter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            displayList();
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
            printf("Default Case.");
            break;
        }
    }

    return 0;
}