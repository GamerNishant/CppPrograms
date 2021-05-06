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


void buildlist(node* &head , int n)
{
    int data;
    cin>>data;

    while(n)
    {
        insertattail(head , data);
        cin>>data;
        n-- ;
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

//reverse list

node* reverselist(node* head)
{
    if(head == NULL or head->next == NULL)
    {
        return head;
    }

    //Else use two pointer method
    node* p = __null;
    node* c = head;
    node* n;
  

    while(c!=NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
  
    return head;
}


//Reversing Linked list as per k

node* llkreverse(node* head, int k)
{
    if(head == NULL or head->next == NULL)
    {
        return head;
    }

    node* start = head;
    node* end = head;
    node* temp , *recvar;
    int loop = k-1;

    //Making loop to advance end to break into pieces
    while(loop)
    {
        end = end->next;
        loop--;
    }

    //assingning recvar to make recursive call
    recvar = end->next;
    end->next = NULL;

    node* smallhead = reverselist(head);
    temp = smallhead;
    loop = k-1;
    while(loop)
    {
        if(temp == NULL)
        {
            break;
        }
        else
        {
            temp = temp->next;
        }
        
        loop -- ;
    }

    temp->next = llkreverse(recvar , k);

    return smallhead;

}

int main()
{

     #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int n , k;
    cin>>n>>k;
    node* head = NULL;
    buildlist(head, n);
    node* newhead = llkreverse(head,k );
    print(newhead);
    return 0;

}
