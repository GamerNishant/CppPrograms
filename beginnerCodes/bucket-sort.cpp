//Bucket Sort needs kind of data of and store them in bucket and do
//Sorting that is similar to counting sort...
#include<bits/stdc++.h>

using namespace std;
/*
let's check how all of that goes in right way or not
because I think when I will design it will create problems for me and so and so

*/

//Functions code

int main()
{

     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Nishant Singh"<<endl;

    bucketsort(arr, n);

    return 0;

}