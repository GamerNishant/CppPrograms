#include<bits/stdc++.h>

using namespace std;

//Functions code


void merge(int *arr, int s, int e)
{
    int mid = (s+e)/2;

    int i =s ;
    int j = mid+1;
    int k =s;

    int temp[100];

    while (i<=mid and j<=e)
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }

        
    else{
        temp[k++] = arr[j++];
    }

    }


    while (i<=mid)
    {
        temp[k++] =  arr[i++];
    }
    

    while (j<=e)
    {
        temp[k++] = arr[j++];
    }


    //Copying all elements from temp to arr

//    int l = 0;
    for (size_t i = s; i <= e; i++)
    {
        arr[i] = temp[i];
  //      l++;
    }
    
    
    
}



void mergesort(int arr[] , int s, int e)
{
    //Base Case
    if(s>=e)
    {
        return;
    }

    //Three Steps for making sort

    int mid = (s+e) /2;

    //Sorting the right part

    mergesort(arr, s, mid);

    //Sorting the left part

    mergesort(arr, mid +1 , e);

    //Merging the left and right sorted part

    merge(arr , s, e);
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

    for(int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Checkpoint"<<endl;

    mergesort(arr,0, n);

    //Print the array

    for(int i = 0 ; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;

}