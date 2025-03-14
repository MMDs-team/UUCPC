#include <bits/stdc++.h>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define endl '\n'
#define int long long
using namespace std;

void solve()
{
    int len, maxi = 1;
    cin >> len;
    int arr[len];

    for (int i{}; i < len; ++i)
    {
        cin >> arr[i];
        if (i < 5)
            maxi *= arr[i];
    }
    
    for (int i{}; i < len; ++i)
        for (int j{i + 1}; j < len; ++j)
            for (int k{j + 1}; k < len; ++k)
                for (int jj{k + 1}; jj < len; ++jj)
                    for (int kk{jj + 1}; kk < len; ++kk) 
                        maxi = max(maxi, arr[i] * arr[j] * arr[k] * arr[jj] * arr[kk]);

    cout << maxi << endl;
}

int32_t main()
{
    MAJOONI
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}