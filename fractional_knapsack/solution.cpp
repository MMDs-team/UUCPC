#include <bits/stdc++.h>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define int long long
#define endl '\n'
using namespace std;

#define p first
#define w second

void solve()
{
    int len, w;
    double value{};
    cin >> len >> w;

    pair<int, int> arr[len];
    for (int i{}; i < len; ++i)
        cin >> arr[i].p >> arr[i].w;

    sort(arr, arr + len, [](auto n1, auto n2)
         { return ((double)n1.p / n1.w) > ((double)n2.p / n2.w); });

    for (int i{}; i < len; ++i)
    {

        if (arr[i].w <= w)
        {
            w -= arr[i].w;
            value += arr[i].p;
        }
        else
        {
            value += arr[i].p * ((double)w / (double)arr[i].w);
            break;
        }
    }
    printf("%.2f", value);
}

int32_t main()
{
    MAJOONI
    // int tc ; cin >> tc; while(tc--)
    solve();
}