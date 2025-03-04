#include <bits/stdc++.h>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define endl '\n'
#define int long long
using namespace std;

const int N = 200005;
const int FILE_COUNT = 20;

map<pair<int, int>, bool> cycle;
map<int, vector<int>> edge;
int delNode[N], len;
bool vis[N], st[N];

void cycle_detection(int cu)
{
    vis[cu] = st[cu] = true;
    for (auto node : edge[cu])
    {
        if (vis[node] && st[node])
        {
            if (!cycle[make_pair(cu, node)])
                ++delNode[cu];
            cycle[make_pair(cu, node)] = true;
        }
        if (!vis[node])
            cycle_detection(node);
    }
    st[cu] = false;
}

void find_cycle(int num)
{
    edge.clear();
    cycle.clear();
    memset(vis, false, sizeof vis);
    memset(st, false, sizeof st);
    memset(delNode, 0, sizeof delNode);

    string file_name = "in/input" + to_string(num) + ".txt";
    ifstream in_file;
    in_file.open(file_name);

    int k, y;
    in_file >> len;

    for (int i = 1; i <= len; i++)
    {
        in_file >> k;
        for (int j{}; j < k; ++j)
        {
            in_file >> y;
            edge[i].push_back(y);
        }
    }
    for (int i = 1; i <= len; i++)
    {
        if (!vis[i])
            cycle_detection(i);
    }

    in_file.close();
}

void rewrite_input(int num)
{
    string file_name = "in/input" + to_string(num) + ".txt";
    ofstream out_file;
    out_file.open(file_name);

    out_file << len << endl;
    for (int node{1}; node <= len; ++node)
    {
        out_file << edge[node].size() - delNode[node] << " ";
        for (auto child : edge[node])
        {
            if (!cycle[make_pair(node, child)])
                out_file << child << " ";
        }
        out_file << endl;
    }
    out_file.close();

    cout << "cycles remove from file " << num << endl;
}

int32_t main()
{
    MAJOONI
    for (int num{1}; num <= FILE_COUNT; num += 2)
    {
        find_cycle(num);
        rewrite_input(num);
    }
}