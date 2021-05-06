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


node* merge(node * a, node* b)
{
    if(a ==  NULL)
    {
        return b;
    }
    
    else if(b == NULL){
        return a;
    }

    node* c;
    
    if(a->data < b->data)
    {
        c = a;
        c->next = merge(a->next , b);

    }

    
    else
    {
        c = b;
        c->next = merge(a , b->next);
    }

    return c;
}

node* midpoint(node* head)
{
    //runner's technique
    if(head ==  NULL or head->next == NULL)
    {
        return head;
    }

    // Make slow and fast and put fast one step head to compete 

    node* slow = head;
    node* fast = head->next;

    //take care of which condition you will put first here
    //because if you put wrong condition first then the other one will
    //be evaluated afterwards the first one
    //especially in case of linked list.
    //because here if I put the end of list condition first then it will 
    //turn to allow loop till infinity and the ending condition will never be executed
    //So beware of that...

    while(fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}


node* mergesort(node* head)
{
    if(head == NULL or head->next == NULL)
    {
        return head;
    }


    //Code will remain similar
    //break it at mid point

    node* mid = midpoint(head);

    node* a = head;
    node* b = mid->next;
    mid->next = NULL;

    a = mergesort(a);
    b = mergesort(b);

    node* c = merge(a, b);
    return c;

}


int main()
{

     #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

     node* head = NULL;
     buildlist(head);
     node* newlist = mergesort(head);
     print(newlist); 

    return 0;

}