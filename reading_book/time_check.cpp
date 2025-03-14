#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define endl '\n'
#define int long long
using namespace std;

const int N = 2e5;

vector<pair<int, int>> gr[N]{};
bool cycle{false};
int mem[N]{};
bitset<N> stk{};

void dfs(int curr)
{
    stk.set(curr);
    mem[curr] = 0;
    for (const auto &[w, v] : gr[curr])
    {
        dfs(v);
        if (stk[v])
        {
            cycle = true;
            break;
        }

        mem[curr] = max(mem[curr], mem[v] + w);
    }

    stk.reset(curr);
}

void solve()
{
    int len, m, ch;
    cin >> len;

    cycle = false;
    stk.reset();
    for (int i{}; i < len; ++i)
    {
        gr[i].clear();
        mem[i] = -1;
    }

    for (int i{}; i < len; ++i)
    {
        cin >> m;

        for (int j{}; j < m; ++j)
        {
            cin >> ch;
            gr[--ch].emplace_back(ch > i, i);
        }
    }

    for (int i{}; i < len; ++i)
        if (mem[i] == -1)
            dfs(i);

    cout << (cycle ? -1 : *max_element(mem, mem + len) + 1) << '\n';
}

int32_t main()
{
    IO
    solve();
}