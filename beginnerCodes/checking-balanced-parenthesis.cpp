#include<bits/stdc++.h>

using namespace std;

bool isbalanced(stack<char> s)
{
    while(s.top() == ')')
    s.pop();
    return s.empty();
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

    stack<char> s;
    string word;
    cin>>word;
    int i = word.length()-1;
    int j = 0;
    while(i)
    {
        s.push(word[j]);
        i--;
        j++;
    }

    cout<<isbalanced(s)<<endl;

    return 0;

}