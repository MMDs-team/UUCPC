#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

typedef long long ll;

ll n{}, s{}, d{};
bool dfs(const ll curr, const ll tar, const ll rem_depth){
    // Base case:
    if(curr == tar) return true;
    if(rem_depth == 0) return false;

    // Recursive case:
    ll riff_idx{(curr <= n? (curr << 1) - 1: (curr - n) << 1)}, 
        shuff_idx{(curr & 1? curr + 1: curr - 1)};
    
    return dfs(riff_idx, tar, rem_depth - 1) or
           dfs(shuff_idx, tar, rem_depth - 1);
}

void solve(){
    cin >> n >> s >> d;

    ll ans{};
    do{
        if(dfs(s, d, ans)) break;
    } while(++ans);

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
