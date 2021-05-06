#include<bits/stdc++.h>

using namespace std;
/*
    Define a class to represent a bank account. Include the following members: 
         Data Members: Name of the depositor, Account No., Type of Account, Balance amount in the account
         Member Functions: (a) To assign initial amount, (b) to deposit an amount, (c) To withdraw an amount after checking the balance, (d) To display name and balance.
         
        Write a Program for handling 10 customers and to test the program. 
*/
class Account{
    int accountnum;
    string type;
    int balance = 0;

    public:
    string name;

    void assigninitial()
    {
        int iAmount;
        cout<<"Enter Initial Amount:";
        cin>>iAmount;
        balance += iAmount;
    
    }

    void deposit()
    {
        int dAmount;
        cout<<"Enter Deposit Money:";
        cin>>dAmount;
        balance += dAmount;

    }

    void withdraw()
    {
        cout<<"Current Balance:"<<balance;
        int n;
        cout<<endl;
        cout<<"Enter withdraw amount:";
        cin>>n;

        balance = balance - n;

        // cout<<"Current Balance:"<<balance;
    }

    void basicdetail()
    {
        cout<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Balance:"<<balance<<endl;
    }

}customer[10];

int main()
{

    //  #ifndef ONLINE_JUDGE 
    // freopen("input.txt", "r", stdin) ;
    // freopen("output.txt", "w", stdout) ;
    // #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL) ; cout.tie(NULL) ;
    // cout.setf(std::ios::boolalpha);

    int cnum;
    cout<<"Enter customer count:";
    cin>>cnum;

    for (int i = 0; i < cnum; i++)
    {
        cout<<"Enter Details for "<<i+1<<" customer :-"<<endl;
        cout<<"Name:";
        string name;
        cin>>name;
        customer[i].name = name;
        customer[i].assigninitial();
        customer[i].deposit();
        customer[i].withdraw();

    }

    //For printing basic details for customer

    for (int  i = 0; i < cnum; i++)
    {
        cout<<"Details of "<<i+1<<" Customer:";
        customer[i].basicdetail();
    }
    

    return 0;

}