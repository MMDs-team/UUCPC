#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

typedef long long ll;

const ll INF{(ll)1e18};

void solve(){
    ll n{}, k{};
    cin >> n >> k;

    ll len{1 << n}, seg{1 << k}, idx{-1}, val{-INF};
    cout << len / seg << '\n';
    for(ll i{}; i < len; ++i){
        ll curr{};
        cin >> curr;

        if(curr > val) idx = i + 1, val = curr;
        if(i % seg == seg - 1){
            cout << idx << ' ';
            idx = -1, val = -INF;
        }
    }
    cout << '\n';
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
