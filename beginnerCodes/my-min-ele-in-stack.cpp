#include<bits/stdc++.h>

using namespace std;

class Stack{
    int top = -1;
    int cur_min = INT_MAX;

    public:
    int arr[100];
    void push(int data)
    {
        if(top<0)
        {cur_min = data;
        arr[++top] =((2*cur_min) - data);
        }

        else if(data < cur_min)
        {
            arr[++top] = 2*data - cur_min;
            cur_min = data;
        }

        else 
        arr[++top] = data;
    }

    int pop()
    {
        int x = arr[top--];
        if(x < cur_min)
        cur_min = 2*cur_min - x;//current min is actually the data of that position
        //that's we why we are going to make it like this so that
        //twice of data at that stage - twice of data - cur_min of below stage
        //gives us current min after popping the element.
        return x;
    }

    int topele()
    {
        return arr[top];
    }

    int getmin()
    {
        return cur_min;
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

    Stack s;
   s.push(3); 
	s.push(5); 
	cout<<s.getmin();
    return 0;

}