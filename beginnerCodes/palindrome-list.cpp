#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    char data;
    node* next;

    node(char d)
    {
        data = d;
        next = NULL;
    }
};


void insertattail(node* &head , char data)
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



void buildlist(node* &head , string word)
{
    int n = word.length();
    int i = n-1;
    while(n)
    {
        insertattail(head , word[i]);
        i--; 
        n-- ;
    }

}

void print (node* head)
{
    node* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data;
        temp =  temp->next;
    }

}

bool checkpalindrome(node * head , string word)
{   
    bool ans = false;
    node* temp = head;
    int i  = word.length();
    int j = 0;
    while(j < i)
    {
        if(temp->data == word[j])
        {
            ans = true;
        }

        else 
        return false;

        temp = temp->next;
        j++ ;
    }

    return ans;
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

    //Program code
    node* head = NULL;
    string word;
    cin>>word;
    buildlist(head , word);
    bool check = checkpalindrome(head ,word);
    cout<<"Palindrome:"<<check<<endl;
    print(head);
    return 0;

}