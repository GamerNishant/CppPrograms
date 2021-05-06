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

node* mergelist(node* a, node* b)
{
    if(a == NULL)
    {
        return b;
    }

    if(b == NULL )
    {
        return a;
    }


    node* newlist ;

    
    if(a->data < b->data)
    {
        newlist = a;
        newlist->next = mergelist(a->next,b);
    }

    else
    {
        newlist = b;
        newlist->next =  mergelist(a, b->next);
    }

    return newlist;
    
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //Program code
    cout << "Enter your Sorted list" << endl;
    node *head1 = NULL;
    node *head2 = NULL;

    buildlist(head1);
    print(head1);
    buildlist(head2);
    print(head2);

    cout<<"check it."<<endl;

    node* newlist = mergelist(head1, head2);

    print(newlist);

    return 0;
}