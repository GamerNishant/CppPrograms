#include<bits/stdc++.h>

using namespace std;

//Functions code
void countingsort(int arr[] , int n)
{
    int largest = INT_MIN;

    for (size_t i = 0; i < n; i++)
    {
        largest = max(largest , arr[i]);
    }

    //Creating the frequency array

    int *freq = new int [largest +1] {0};

    for (size_t i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    //putting elements back into the array by reading freq array

    int j = 0;
    for (size_t i = 0; i <= largest; i++)
    {
        while (freq[i] > 0)
        {
            arr[j] = i;
            freq[i]--;
            j++;
        }
        
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

    int n;
    cin>>n;

    int arr[n];

    for(int i = 0 ; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Checkpoint"<<endl;

    countingsort(arr, n);


    //Printing the array

    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;

}