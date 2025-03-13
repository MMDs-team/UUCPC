#include <bits/stdc++.h>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define int long long
#define endl '\n'
using namespace std;

vector<int> mem;
int len;

int best(int i, int j, int r, int mul)
{
    if (!r)
        return mul;
    return max(best(i + 1, j, r - 1, mem[i] * mul), best(i, j - 1, r - 1, mem[j] * mul));
}

void solve()
{
    int remain = 5, count = 0;
    cin >> len;
    mem.clear();
    mem.resize(len);
    for (int i = 0; i < len; i++)
        cin >> mem[i];
    sort(mem.begin(), mem.end());
    cout << best(0, len - 1, 5, 1) << endl;
}

int32_t main()
{
    MAJOONI
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}