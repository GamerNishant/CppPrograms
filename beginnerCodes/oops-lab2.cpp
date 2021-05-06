#include<bits/stdc++.h>

using namespace std;

void tempconverter(int n)
{
    //converting farenheit to celcius
    float x = n;

    float c =( (x-32) * 5)/9;

    cout<<x<< "F is equal to " << c <<"C"<< endl;
    return;
}

int main()
{

    //  #ifndef ONLINE_JUDGE 
    // freopen("input.txt", "r", stdin) ;
    // freopen("output.txt", "w", stdout) ;
    // #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL) ; cout.tie(NULL) ;

    float f;
    cout<<"Enter you farenheit:";
    cin>>f;
    tempconverter(f);   

    return 0;

}