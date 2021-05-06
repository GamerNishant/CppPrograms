#include<bits/stdc++.h>

using namespace std;

//WE are making special stack array to store min for O(1) time.

class Stack{
    int top = -1;
    int arr[100];

    public:
    void push(int x)
    {
        arr[++top] = x;
    }

    int pop()
    {
        int x = arr[top--];
        return x;
    }

    bool isempty()
    {
        if(top > -1)
        {
            return false;
        }

        return true;
    }

    bool isfull()
    {
        if(top >= 100)
        {
            return true;
        }

        else 
        return false;
    }

};

//Stating the Inheritance

class SpecialStack : public Stack
{
    Stack min;

    public:
    void push(int x);
    int pop();
    int getmin();

};

//Now since we are designing the class so we can directly access function for inherited class

void SpecialStack :: push(int x)
{
    if(isempty() == true)
    {   Stack::push(x);
        int y = x;
        min.push(x);
    }

    else
    { 
        Stack::push(x); 
        int y = min.pop(); 
        min.push(y); 
        if (x < y) 
            min.push(x); 
        else
            min.push(y); 
    } 

}


int main()
{

     #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    

    return 0;

}