#include<bits/stdc++.h>

using namespace std;

//In this design enque operation is costly...

class Queue{
    stack <int> s1;
    stack <int> s2;

    public:
    void enque(int x)
    {   
        if(s1.empty())
          s1.push(x);
        
        else{
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            s1.push(x);

            //copying it back
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

      int deQueue() 
    { 
       // if first stack is empty 
        if (s1.empty()) { 
            cout << "Q is Empty"; 
            exit(0); 
        } 
  
        // Return top of s1 
        int x = s1.top(); 
        s1.pop(); 
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

    Queue  q;
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