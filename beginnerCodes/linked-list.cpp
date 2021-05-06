/*#include<bits/stdc++.h>
//It is actually concatenating the existing list with the input
//I tried it with new variable denoting the new list but 
//It didn't work as it is supposed to..

using namespace std;

class node{
    public:
    int data;
    node* next;

    //constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertathead(node * &head/*here we need to pass it by reference. , int data)
{
    node * n = new node (data) ;
    n->next = head;
    head = n;
}

void print (node * head)
{
    node* temp = head;
     while (temp!=NULL)
     {
        cout<<temp->data<<" ";
        temp = temp->next;
     }
     
}


//function for entering node at m position inside the list
void insertatmiddle(node*  &head , int data , int p)
{
    if (head == NULL or p==0)
    {
        insertathead( head,data);
        return;
    }

    else
    {
        int jump =1;
        node* temp = head;
        //Blunder that I made was I just define temp with ampersand
        //then it becomes address and their value is ignored for previous section till p-1
        //But data of p-1 is safe because control gone out of the loop at that time.
        while (jump <= p-1)
        {
            temp = temp->next;
            jump +=1;
        }

        node *n = new node (data);
        n->next = temp->next;
        temp->next = n;
        
    }
}

int length(node* head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len += 1;
    }
    return len;
}

//Program for inserting at the tail
void insertattail(node* &head , int data)
{
    if(head == NULL)
    {
        head = new node (data);
        return;
    }

    node * tail = head;
    while (tail -> next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new node(data);
    return;
    
}

//Now program for building the linked list using input
void buildlist(node* &head)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        insertattail(head , data);
        cin>>data;
    }
}


//----------OPERATOR OVERLOADING-----------//

//here we will make it such that we can insert list as cin>>list; 
//and output it like cout<<list;

istream& operator >> (istream& is , node* &head)
{
    buildlist(head);
    return is ;
}


ostream& operator << (ostream& os , node* &head)
{
    print(head);
    return os ;
}

//----------------------------------------//

int main()
{

     #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    node * head =   NULL;

    insertathead(head, 1);
    insertathead(head, 2);

    insertathead(head, 3);

    insertathead(head, 4);

    insertathead(head, 5);
    insertatmiddle(head, 11,3);
    // cout<<endl;

    cout<<length(head);

    insertattail(head , 8);
    insertattail(head , 8);
    insertattail(head , 8);
    insertattail(head , 8);
    insertattail(head , 8);

    cout<<endl;
    cout<<length(head)<<endl;

    print(head);
    cout<<endl;
 //   node *head1 =NULL;
    buildlist(head);
    print(head);

    // node *head2 = NULL;
    cout<<endl;
      cin>>head;
      cout<<head;

    //Now operator overloading is going on...


    return 0;

}
*/