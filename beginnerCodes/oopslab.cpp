#include<bits/stdc++.h>

using namespace std;

class student
{
    private:
    string name;
    int marks;
    int Reg_no;
    string address;

    public:
    void initialize(string str, int mrks, int reg, string add)
    {
        name = str;
        marks = mrks;
        Reg_no = reg;
        address = add;
    }

    void display()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Registration Number:"<<Reg_no<<endl;
        cout<<"Marks:"<<marks<<endl;
        cout<<"Address:"<<address<<endl; 
        
    }

};

int main()
{

     #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    student s1;
    string name, adrs;
    int reg, marks;


    cout<<"Enter Name:"; cin>>name;cout<<endl;
    cout<<"Enter Registration Number:"; cin>>reg;cout<<endl;
    cout<<"Enter Marks:"; cin>>marks;cout<<endl;
    cout<<"Enter Address:"; cin>>adrs;
    cout<<endl;
    s1.initialize(name,marks,reg,adrs);
    s1.display();

    return 0;

}