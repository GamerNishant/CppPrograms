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

//Kth element from last

node* lastk(node* head , int k)
{
    if(head == NULL and head->next == NULL)
    {
        return head;
    }

    //Else 

    node* slow = head;
    node* fast = head;

    //node* fast = check;
    // cout<<endl;
    while(k)
    {
        // cout<<"Value of k is:"<<k<<endl;
        // cout<<"Value of fast is:"<<fast->data<<endl;
        fast = fast->next;
        k = k-1;
    }
    // cout<<endl;
    // cout<<slow->data<<" "<<fast->data<<endl;
    while(fast != NULL )
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
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
    int k ;
    cin >> k;
    buildlist(head);
    print(head);
    node* kelement = lastk(head, k);
    cout << endl << kelement->data;
    return 0;

}