#include<bits/stdc++.h>

using namespace std;

//Functions code

int merge(int *arr, int s, int e)
{
    int mid = (s+e)/2;

    int i =s ;
    int j = mid+1;
    int k =s;

    int temp[100];
    int count = 0;
    //Merging parts here by comparison

    while (i<=mid and j<=e)
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }

        
    else{

        cout<<"Inverting " << arr[j] << " with " << arr[i] <<endl;
        temp[k++] = arr[j++];
        count += mid - i + 1;
    }

    }

    //Merging left side spare elements
    while (i<=mid)
    {
        temp[k++] =  arr[i++];
    }
    
    // Merging right side spare elements
    while (j<=e)
    {
        temp[k++] = arr[j++];
    }


    //Copying all elements from temp to arr

    for (size_t i = s; i <= e; i++)
    {
        arr[i] = temp[i];

    }

    return count;        
}

int inversion_count(int arr[] , int s, int e)
{
    //Base Case
    if(s>=e)
    {
        return 0;
    }

    
    //Implementing through merge sort

    int mid = (s+e)/2;
    int x = inversion_count(arr, s, mid);
    int y = inversion_count(arr, mid +1 , e);
    int z = merge(arr, s,e);


    return x+y+z;


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


    int ans = inversion_count(arr, 0, n);

    //Printing the array 

    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    cout<< "With inversions:" << ans<<endl;

    return 0;

}