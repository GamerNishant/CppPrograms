//tail->next = new node(data);//don't get it why this is all happening
//Now doing here c ka next means we are reducing the number of times we will allow to run this loop
/*
    One most important thing inside the list
    they have their position fixed but their link can be modified
    so never think in terms of moving their position
    but in terms of link
*/
#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* next;

    //Check why this is working and "this" keyword is not working properly
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

    //Now if head is not empty then move all the way down to tail
    //Setting head as tail 
    node* tail = head;

    //Now moving down

    while(tail->next!=NULL)
    {
        tail = tail->next;
    }

    //Now making acutally if we didn't make it to next then it
    //every time new tail and since we are not connecting it to head it will still remain there
    //and also since we are not accessing the tail back so it will always remain there and get updated
     
    tail->next = new node (data);

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

void reverse(node* &head)
{
    //Normal reversing is based on three steps 

    //first to make a container that can store the next element temporarily

    node* c = head;
    node* p = NULL;
    node* n ;

    //Now working is based on the fact that making 
    //current pointing to previous and making previous as head
    //and when these two we done then we will make the next pointer as current pointer

    while(c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }

    //Now making previous node as head so that null case 
    //got removed
    head = p;

}

void print(node* head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}

node* recReverse(node* head)
{
    if(head == NULL or head->next == NULL)
    {
        return head;
    }

    //Now recursive will work like 

    //1. Go all the way down
    node* smallhead = recReverse(head->next);
        
    node* c = head;
    //Here instead of using two pointer just use that 
    //to make next and next
    //Now we are returning small head because of the fact that
    //It will be calculating everytime by going down the road...       
    c->next->next = c;
    c->next = NULL;

    return smallhead;

}

/*
    Now reversing list using recursion by
    the help of two pointer actually one pointer help to position
    another pointer and then this first pointer is updated to NULL
    now after updating it to NULL you need to make sure 
    that these pointer are again created at the time of execution
    where we want to switch...
*/


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
    reverse(head);
    print(head);
    cout<<endl;
   print (recReverse(head));
    return 0;

}               