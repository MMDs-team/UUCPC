#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

typedef long long ll;

void solve(){
    ll n{}, s{}, d{};
    cin >> n >> s >> d;

    queue<ll> q{};
    ll dist[(n << 1) + 1];
    memset(dist, -1, sizeof dist);

    q.emplace(s);
    dist[s] = 0;
    while(q.size()){
        ll curr{q.front()};
        q.pop();
        if(curr == d) break;

        ll riff_idx{(curr <= n? (curr << 1) - 1: (curr - n) << 1)}, 
           shuff_idx{(curr & 1? curr + 1: curr - 1)};
        
        if(dist[riff_idx] == -1){
            dist[riff_idx] = dist[curr] + 1;
            q.emplace(riff_idx);
        }
        if(dist[shuff_idx] == -1){
            dist[shuff_idx] = dist[curr] + 1;
            q.emplace(shuff_idx);
        }
    }

    cout << dist[d] << '\n';
}

int main(){
    IO

    ll tc{1ll};
    // cin >> tc;
    while(tc--) solve();
    
    return 0;
}
