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

node* getnode(node* &head ,int data)
{
    node* temp = head;
    //use double equal to compare not single equal to...
    while(temp->next != head)//I am repeating this error multiple times take care of that
    {
        if(temp->data ==  data)
        return temp;

        temp = temp->next;
    }

    if(temp->data ==  data)
    return temp;
    else
    return NULL;
}

void deletenode(node* &head , int data)
{
    node* del = getnode(head,data);
    if(del == NULL)
    {
        cout<<"NO such node is present in list."<<endl;
        return;

    }

    if(head != del)
    {
        head = del->next;
    }

    node* temp = head;
    while(temp->next != del)
    {
        temp = temp->next;
    }

    temp->next = del->next;;

    delete del;
}

int main()
{

     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    //deleting a single node inside from circular list...

    return 0;

}
