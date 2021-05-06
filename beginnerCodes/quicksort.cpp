//Problem Identified
// 5 
// 3 5 1 4 2
//Output:
// 2 1 3 4 5 
#include<bits/stdc++.h>

using namespace std;

//Functions code
int partition(int *arr , int s, int e)
{
    int i = s-1;
    int j = s;
    int pivot = arr[e];

    for (; j <= e-1; j++)
    {
        if (arr[j] <= pivot)
        {
            i = i+1 ;
            swap(arr[i] , arr[j]);
        }
        j = j+1;
    }

    swap(arr[i+1] , arr[e]);
    return i+1;
    
}

void quicksort(int arr[] , int s, int e) 
{
    if(s>=e)
    {
        return;
    }

    //Recursive Case

    

    int p = partition (arr, s, e);

    //Sorting left part

    quicksort(arr, s, p - 1);

    //Sorting right part

    quicksort(arr, p , e);
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

    for(int i = 0 ; i< n; i++)
    {
        cin>>arr[i];
    }

    quicksort(arr, 0 , n);

    //Printing the array 

    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;

}