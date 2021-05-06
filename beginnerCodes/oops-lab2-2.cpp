#include<bits/stdc++.h>

using namespace std;

void pattern(int n)
{
    for(int j = 1; j <= n ; j++)
{    //maintiaining whitespace
    for(int i = n-j; i>0 ; i--)
    {
        cout<<" ";
    } 
    //Priting digits
    for(int i = 1 ; i <= j ;i++)
    {
        cout<<i<<" ";
    } 

    cout<<endl;
}
}

int main()
{

    //  #ifndef ONLINE_JUDGE 
    // freopen("input.txt", "r", stdin) ;
    // freopen("output.txt", "w", stdout) ;
    // #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL) ; cout.tie(NULL) ;

    int n;
    cout<<"Enter length:";
    cin>>n;
    pattern(n);

    return 0;

}