#include <bits/stdc++.h>

using namespace std;

void wavesort(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        cout << "Current :" << i << endl;
        //previous element
        if (arr[i] < arr[i - 1] and i != 0)
        {
            cout << "swapping " << arr[i] << " and " << arr[i - 1] << endl;
            swap(arr[i], arr[i - 1]);
        }

        //Next element
        if (arr[i] < arr[i + 1] and i != (n - 1))
        {
            cout << "swapping " << arr[i] << " and " << arr[i + 1] << endl;

            swap(arr[i], arr[i + 1]);
        }
    }
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

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    wavesort(arr, n);

    //Printing the sorted array

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
