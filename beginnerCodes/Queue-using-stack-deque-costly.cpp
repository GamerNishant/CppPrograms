#include<bits/stdc++.h>

using namespace std;

//Making deque costly code
//function call stack is also known as recursion...

class Queue{
    stack <int> s1, s2;
    public:
    void enque(int n)
    {
        s1.push(n);
    }

    int deQueue()
    {
        if(s1.empty() and s2.empty())
        {
            cout<<"Queue is empty."<<endl;
            exit(0);
        }

        //Else you need to copy all elements back to stack 1 to stack 2.

        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

        }

            int x = s2.top();

            s2.pop();
            return x;
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

    Queue q;
     q.enque(10);
    q.enque(20); 

    q.enque(30); 

    q.enque(40); 
    q.enque(50); 

    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    

    return 0;

}