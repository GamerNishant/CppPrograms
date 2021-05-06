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


void sortedList(node* &head, int data)
{   
    node* newnode = new node (data) , *temp;
    
    //Insert in the beginning
    if(head == NULL or data < head->data)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;

    //Insert in the middle
    //Reason is temp ka next temp se pehle null hoga that's why we have to check both in 
    //order to make sure that we reach the last node 
    //and also to the end of list.
    //end of list is NULL.
    while(temp != NULL and temp->next!=NULL)
    {   
        if(data < temp->next->data)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            return; 
        }

        temp = temp->next;
    }

    //insert at tail

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;

}


//Building Sorting list as new 
node* sortinsertion(node* head)
{
    node* newhead = NULL;
    node* currentnode = head;

    while(currentnode != NULL)
    {
        sortedList(newhead, currentnode->data);
        currentnode = currentnode->next;
    }

    return newhead;
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
 
    int size;
    cin>>size;
    buildlist(head, size);
    node* newhead = sortinsertion(head);
    print(newhead);    

    return 0;

}