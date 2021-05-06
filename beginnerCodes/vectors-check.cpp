#include<bits/stdc++.h>
#include<vector>

using namespace std;

//Functions code

int main()
{

     #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    //Program code
    vector <int> a;
    vector <int> b(5,10);
    vector <int> c(b.begin() , b.end());

    vector <int> d {1,2, 3,4,5};

    //How to iterate over vectors --
    //use of vectors are similar to array
    //but there declaration is different and
    //they have few different functionalites in addition to array

    for(int i= 0; i<c.size() ; i++)
    {
        cout<<c[i]<<",";
    }

    cout<<endl;
    //auto here is going to replace vector<int> :: iterator
    for (auto it = b.begin(); it != b.end(); it++)
    {
        cout<<(*it) <<",";
    }
    cout<<endl;
    
    //for each loop
    for(int x:d)
    {
        cout<<x<<",";
    }

    //More function--

    c.push_back(78); //pushes element in the end of vector
    // by doubling their size
    // must remember that the vector never shrinks it always grow but never shrink

    //understading the memory level difference

    cout<<endl;
    // declares the elements present in it
    cout<<a.size()<<endl;
    cout<<b.size()<<endl;
    cout<<c.size()<<endl;

    // declares the capacity of that vector container
    cout<<a.capacity()<<endl;
    cout<<b.capacity()<<endl;
    cout<<c.capacity()<<endl;


// Declares the maximum upgradable size available to that vector
    cout<<a.max_size()<<endl;
    cout<<b.max_size()<<endl;
    cout<<c.max_size()<<endl;

    // Now time comes for various other function for 
    // vectors that are or would be very useful in future
    // clear() : completely wipes all data inside the vector
    // reserve() : It enables us to reserve some space for expanding of vector in that case doubling is avoided.
    // erase() : It can erase a particular element or erase a list inside the vector or you can say series.
    // empty() : returns boolean true and false as per the vector is empty or not.
    // front() : returns element at the front 
    // back()  : returns element at the back

    return 0;

}