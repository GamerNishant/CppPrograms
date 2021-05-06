#include<bits/stdc++.h>

using namespace std;

//Functions code
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

//Even after odd function

void evenafterodd(node* &head)
{
    node* newevenlist = NULL;
    node* newoddlist = NULL;

    //while traversing make oddlist and evenlist and append it together and then
    //assign it to head

    //for odd process
    node* temp = head;
    node* evenhead = newevenlist;
    node* oddhead = newoddlist;
    bool second = true;
    bool first = true;
    while(temp!= NULL)
    {
        if(temp->data % 2 != 0)
        {
                insertattail(newoddlist , temp->data);

        }

        else
        {
                insertattail(newevenlist , temp->data);
        }
        
        temp = temp->next;
    }

    
    //Reaching to the end of firstlist
    temp = newoddlist;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = newevenlist;

    head = newoddlist;
}


int main()
{

     #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    cout.setf(std::ios::boolalpha);

    int n;
    cin>>n;
    node* head = NULL;
    buildlist(head ,n);
    evenafterodd(head);
    print(head);
    return 0;

}