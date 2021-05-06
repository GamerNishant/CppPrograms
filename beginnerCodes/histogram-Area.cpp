#include<bits/stdc++.h>

using namespace std;

int maxareahistogram(int arr[] , int n)
{
    int area , max = 0;
    
    stack<int> index;

    int i = 0;

//This is the case for any minimum bar found after the maximum of bars.
    while(i<n)
    {
        if(index.empty()|| arr[index.top()] <= arr[i])
        {
            index.push(i++);
        }

        else
        {
            //Popping Case
            int x = index.top();
            index.pop();

            //after poping I need to calculate the area of that removed bar
            area = (arr[x] * (index.empty() ? i : (i - index.top() - 1)) );

            // i++;

               if(area > max)
                {
                    max = area;
                }
                
        }
        
     
    }

//Now for that left top bars means with increasing order you need calculate them
while(!index.empty())
{
       int x = index.top();
            index.pop();

            //after poping I need to calculate the area of that removed bar
            area = (arr[x] * (index.empty() ? i : (i - index.top() - 1)) );

            // i++;

               if(area > max)
                {
                    max = area;
                }
}
    return max;
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

    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }

    int maxArea = maxareahistogram(arr, n);

    cout<<"Maximum Area: "<< maxArea << endl;

    return 0;

}   