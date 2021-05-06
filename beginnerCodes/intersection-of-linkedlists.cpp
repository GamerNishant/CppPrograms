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

//Intersection finding code
void findintersection(node* head1, node* head2)
{
    if(head1 == NULL or head2 == NULL)
    {
        return ;
    }

    node* first = head1;
    node* second = head2;

    while(first->next!=NULL)
    {   
        while(second!=NULL)
     
     {   if(first->data == second->data)
        {
            cout<<first->data <<endl;
            return;
        }
        second = second->next;

    }
        first = first->next;
        second = head2;
    }
            cout<<"-1" <<endl;

};

int main()
{

     #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    cout.setf(std::ios::boolalpha);

    //Program code
    int n1;
    int n2;
    cin>>n1;
    node* head1 , *head2;
    head1 = head2 = NULL;
    buildlist(head1 , n1);
    cin>>n2;
    buildlist(head2, n2);
    findintersection(head1, head2);
    return 0;

}   