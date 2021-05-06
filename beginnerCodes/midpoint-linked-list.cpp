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

//Finding mid point using runner technique
//Break into modules every problem
//Like for runner technique 
//like in runner technique we go like
//One will walk one step the other will walk two steps

node* midpoint (node* head)
{
    if(head->next == NULL or head ==NULL)
    {
        return head;
    }

    node* slow = head;
    node* fast = head->next;

    while(fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

//Now we are allowing one of the pointer to be one step ahead 
//because of the fact that n-k+1 is the kth element from the last 
//So even it is midpoint you need to find it from last so make it
//likewise...


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
    print(head);
    node* mid = midpoint(head);
    cout<<endl<<mid->data;
    return 0;

}