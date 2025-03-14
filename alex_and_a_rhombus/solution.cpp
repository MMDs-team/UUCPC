#include <bits/stdc++.h>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define int long long
#define endl '\n'
using namespace std;

void solve()
{
    int num, plus = 0, sums = 1;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        sums += plus;
        plus += 4;
    }
    cout << sums;
}

int32_t main()
{
    MAJOONI
    // int tc ; cin >> tc; while(tc--)
    solve();
}