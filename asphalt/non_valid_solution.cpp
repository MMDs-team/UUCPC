#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

typedef long long ll;

const ll N{(ll)1e5}, INF{(ll)1e18};

vector<pair<ll, ll>> gr[N]{};
void dijkstra(const ll src, vector<ll>& dist){
    priority_queue<pair<ll, ll>> q{};

    q.emplace(0, src);
    dist[src] = 0;

    while(q.size()){
        auto [d, curr] = q.top();
        q.pop();
        d = -d;

        if(d != dist[curr]) continue;

        for(auto [w, v]: gr[curr]){
            w += d;

            if(w < dist[v]){
                q.emplace(-w, v);
                dist[v] = w;
            }
        }
    }
}

void solve(){
    ll n{}, m{};
    cin >> n >> m;

    for(ll i{}; i < m; i++){
        ll v1{}, v2{};
        cin >> v1 >> v2;

        gr[--v1].emplace_back(1, --v2);
        gr[v2].emplace_back(1, v1);
    }

    vector<ll> d1(n, INF), d2(n, INF);
    dijkstra(0, d1);
    dijkstra(n - 1, d2);

    ll d{d1[n - 1]}, ans{};
    for(ll i{}; i < n; i++) for(const auto& [w, v]: gr[i]) if(d1[i] + w + d2[v] == d) ans += w;
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
