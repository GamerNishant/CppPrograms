#include<bits/stdc++.h>

using namespace std;

//Implementing using array 

class Stack {
    int top;
    
    public:
    int arr[100];
bool push(int data);
    int pop();
    int peek();
    bool isempty();
    Stack ()
    {
        top = -1;
    }    
};

//External defination of member functions is----

//return_type class_name :: Function_name()
//{}

bool Stack :: push(int data)//Stack is actually reserved keyword for cpp stl
{
    if(top > 100)
    {
        cout<<"Stack  Overflow:"<<endl;
        return false;
    }

    arr[++top] = data;
    cout<<arr[top] << " Pushed into stack."<<endl;
    return true;
}

int Stack :: pop()
{
    cout<<arr[top--]<<" is poped out."<<endl;
    return 0;
}

bool Stack :: isempty()
{
    if(top > -1)
    return false;

    return true;
}

int Stack :: peek()
{
    cout<<arr[top]<<" is the top element."<<endl;
    return 0;
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
    Stack s;
    s.push(10);
    s.push(90);
    s.pop();
    cout<<"Is stack empty :"<<s.isempty();

    return 0;

}

// /* C++ program to implement basic stack 
// operations */
// #include <bits/stdc++.h> 

// using namespace std; 

// #define MAX 1000 

// class Stack { 
// 	int top; 

// public: 
// 	int a[MAX]; // Maximum size of Stack 

// 	Stack() { top = -1; } 
// 	bool push(int x); 
// 	int pop(); 
// 	int peek(); 
// 	bool isEmpty(); 
// }; 

// bool Stack::push(int x) 
// { 
// 	if (top >= (MAX - 1)) { 
// 		cout << "Stack Overflow"; 
// 		return false; 
// 	} 
// 	else { 
// 		a[++top] = x; 
// 		cout << x << " pushed into stack\n"; 
// 		return true; 
// 	} 
// } 

// int Stack::pop() 
// { 
// 	if (top < 0) { 
// 		cout << "Stack Underflow"; 
// 		return 0; 
// 	} 
// 	else { 
// 		int x = a[top--]; 
// 		return x; 
// 	} 
// } 
// int Stack::peek() 
// { 
// 	if (top < 0) { 
// 		cout << "Stack is Empty"; 
// 		return 0; 
// 	} 
// 	else { 
// 		int x = a[top]; 
// 		return x; 
// 	} 
// } 

// bool Stack::isEmpty() 
// { 
// 	return (top < 0); 
// } 

// // Driver program to test above functions 
// int main() 
// { 
//       #ifndef ONLINE_JUDGE 
//     freopen("input.txt", "r", stdin) ;
//     freopen("output.txt", "w", stdout) ;
//     #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL) ; cout.tie(NULL) ;
// 	class Stack s; 
// 	s.push(10); 
// 	s.push(20); 
// 	s.push(30); 
// 	cout << s.pop() << " Popped from stack\n"; 

// 	return 0; 
// } 
