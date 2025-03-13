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
    int num, plus = 0;
    cin >> num;
    int arr[num + 1];
    arr[0] = 1;
    for (int i = 1; i <= num; i++)
    {
        arr[i] = arr[i - 1] + plus;
        plus += 4;
    }
    cout << arr[num];
}

int32_t main()
{
    MAJOONI
    // int tc ; cin >> tc; while(tc--)
    solve();
}