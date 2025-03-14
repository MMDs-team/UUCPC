#include <bits/stdc++.h>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define endl '\n'
#define int long long
using namespace std;

vector<int> arr;

int max_mul(int i, int count = 5, int mul = 1)
{
    if (!count)
        return mul;
    if (count == i + 1)
        return max_mul(i - 1, count - 1, arr[i] * mul);
    return max(max_mul(i - 1, count - 1, arr[i] * mul), max_mul(i - 1, count, mul));
}

void solve()
{
    int len;
    cin >> len;
    arr.resize(len);

    for (int i{}; i < len; ++i)
        cin >> arr[i];

    cout << max_mul(len - 1) << endl;;
}

int32_t main()
{
    MAJOONI
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}