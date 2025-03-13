#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

typedef long long ll;

const ll N{(ll)1e5}, INF{(ll)1e18};

vector<ll> gr[N]{};
void bfs(const ll src, vector<ll>& dist){
    queue<ll> q{};
    
    q.emplace(src);
    dist[src] = 0;
    while(q.size()){
        ll curr{q.front()};
        q.pop();

        for(const auto& x: gr[curr]){
            if(dist[x] == INF){
                dist[x] = dist[curr] + 1;
                q.emplace(x);
            }
        }
    }
}

void solve(){
    ll n{}, m{};
    cin >> n >> m;

    for(ll i{}; i < m; ++i){
        ll v{}, w{};
        cin >> v >> w;

        gr[--v].emplace_back(--w);
        gr[w].emplace_back(v);
    }

    vector<ll> d1(n, INF), d2(n, INF);
    bfs(0, d1);
    bfs(n - 1, d2);

    ll d{d1[n - 1]}, ans{};
    for(ll i{}; i < n; ++i) for(const auto& x: gr[i]) if(d1[i] + 1 + d2[x] == d) ++ans;

    cout << ans << '\n';
}

int main(const int argc, const char** argv){
    IO

    if(argc == 2){
        freopen(argv[1], "r", stdin);
        freopen(argv[2], "out.txt", stdout);
    }

    ll tc{1ll};
    // cin >> tc;
    while(tc--) solve();

    return 0;
}
