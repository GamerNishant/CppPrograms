#include<bits/stdc++.h>

/*
    functions available for stl stack basic one's

    push 
    pop
    top
    size
    empty
    //stack has empty not isempty like list take care of that

*/

using namespace std;

void printstack(stack <int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return;
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

    stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout<<"Stack Status:"<<endl;
    printstack(s);

    cout<<"Is stack is empty:"<<s.empty()<<endl;
    cout<<"Size of stack:"<<s.size()<<endl;

    s.pop();
    s.pop();

    cout<<"Stack Status:"<<endl;
    printstack(s);

    return 0;

}