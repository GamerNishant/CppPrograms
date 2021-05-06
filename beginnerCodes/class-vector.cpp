#include<bits/stdc++.h>

using namespace std;

/*
Write a class to represent a vector (a series of float values). Include member functions to perform the following tasks: 
      (a) To Create the vector
      (b) To modify the value of a given element
      (c) To multiply by a scalar value
      (d) To display the vector in the form (10, 20, 30,...)
      (e) To add two vectors using friend function and display the resultant vector
      Write a program to test your class.
*/

class vectorfloat{
    float arr[100];
    int veccount;

    public:
    void create()
    {
        cout<<"Enter vector count:";
        cin>>veccount;

        cout<<"Enter Values for them:";
        for (size_t i = 0; i < veccount; i++)
        {
            cin>>arr[i];
        }
        
    }

    void create(int number , int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = number;
        }
        
    }

    void modify()
    {
        float vector;
        cout<<"Enter Value for modifying element:";
        cin>>vector;

        int pos;

        for (int i = 0; i < veccount; i++)
        {
            if(arr[i] == vector)
            {
                pos = i;
            }
        }

        cout<<"Enter New Value:";
        cin>>vector;

        arr[pos] = vector;
        
    }

    void scalarMultiply()
    {
        int scalar;
        cout<<"Enter Scalar:";
        cin>>scalar;

        for(int i = 0; i< veccount;i++)
        {
            arr[i] = arr[i] * scalar;
        }
    }

    void display()
    {
        cout<<"All values inside vector are:"<<endl;
        for (int i = 0; i < veccount; i++)
        {
            cout<<arr[i]<<", ";
        }
        
    }

    void friendfn(vectorfloat a, vectorfloat b)
    {
        // vectorfloat c;
        for(int i = 0 ; i < max(a.veccount , b.veccount) ; i++)
        {
            arr[i] = a.arr[i] + b.arr[i];
        }

        //Printing it back
        cout<<"Resultant Vector:";
        for (int i = 0; i < max(a.veccount , b.veccount); i++)
        {
            cout<<arr[i]<<", ";
        }
        
    }

    int size()
    {
        return veccount;
    }
};

int main()
{

    //  #ifndef ONLINE_JUDGE 
    // freopen("input.txt", "r", stdin) ;
    // freopen("output.txt", "w", stdout) ;
    // #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL) ; cout.tie(NULL) ;
    // cout.setf(std::ios::boolalpha);

    //Program code
    int n;
    cout<<"Enter Number of vector you want to make:";
    cin>>n;
    vectorfloat arr[n];

    for (int i = 0; i < n; i++)
    {   
        cout<<"Enter Details for "<<i+1<<" vector"<<endl;
        arr[i].create();
        arr[i].modify();
        arr[i].scalarMultiply();
        arr[i].display();
        cout<<endl;
    }

    //for addition of two vectors

    cout<<"Enter Vector's positions for adding them:";
    vectorfloat c;

    int pos1, pos2;
    cin>>pos1>>pos2;

    // c.create(0 , max(arr[pos1-1].size() , arr[pos2-1].size()));

    c.friendfn(arr[--pos1] , arr[--pos2]);
    return 0;

}