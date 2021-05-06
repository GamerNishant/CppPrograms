//Not working I don't know why but tommorow I will figure it out...
#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};


void insertattail(node* &head , int data)
{
    if(head == NULL)
    {
        head = new node (data);
        return;
    }
    //Base on three steps
    node* tail = head;

    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new node(data);//next is necessry to build vonnection
    return;
}


void buildlist(node* &head)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        insertattail(head , data);
        cin>>data;
    }

}

void print (node* head)
{
    node* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp =  temp->next;
    }

}

void circularlist(node* &head , int data)
{
    node* ptr1 = new node(data);
    node* temp = head;

    ptr1->next = head;
    if(head != NULL)
    {
        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = ptr1;
    }

    else
    {
        
        ptr1->next = ptr1;
    }

    head = ptr1;
    
}

int main()
{

     #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    //Program code
    node* head = NULL;
    buildlist(head);
    print(head);
    circularlist(head, head->data);
    // print(head);

    return 0;

}