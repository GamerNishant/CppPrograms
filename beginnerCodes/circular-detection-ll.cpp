#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertattail(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    //Base on three steps
    node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new node(data); //next is necessry to build vonnection
    return;
}

void buildlist(node *&head)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertattail(head, data);
        cin >> data;
    }
}

void print(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool detectcycle(node* head)
{
    node* slow = head;
    node* fast = head->next;

    while(fast!= NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            return true;
        }
    }

    return false;
}

void removal(node* head ,node* cycle)
{
    node* ptr1 = head;
    node* ptr2 = cycle;

    while(ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr2->next = NULL;

}

//Question is why this algo works
//


int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    node *head = NULL;
    buildlist(head);
    print(head);
    return 0;
}