#include <bits/stdc++.h>
#include <stack>
#include <climits>

using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);

    stack<int> s;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        cout << "Changes at " << i << " iteration." << endl;

        while (!s.empty() && nums[s.top()] <= nums[i % n])
        {
            cout << "Popping :" << s.top() << " after checking " << nums[s.top()] << " <= " << nums[i % n] << endl;
            s.pop();
        }

        res[i % n] = (s.empty() ? -1 : nums[s.top()]);
        cout << "Current Value of res at " << i % n << " :" << res[i % n] << endl;
        cout << "Storing index of:" << i % n << endl;
        s.push(i % n);
    }

    return res;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.setf(std::ios::boolalpha);

    int n;
    cin >> n;
    int loop = n;
    vector<int> v, result;
    while (n)
    {
        int data;
        cin >> data;
        v.push_back(data);
        n--;
    }

    for (int i = 0; i < loop; i++)
    {
        cout << v[i] << " ";
    }

    result = nextGreaterElements(v);

    for (int i = 0; i < loop; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}

//So how all this is working I still have no idea but police is working and find it I am a know it all type person this is right or not

//can you make my life easier by making this as per my adjustments

//This is all we know I ride my bike up to the road down to street right through the city
//I go every where you go from chicago to the new york city
//I go in the city you go and smoke it all like through the windows and this is all we
// know ooooooo..
