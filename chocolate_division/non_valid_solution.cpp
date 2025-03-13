#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

typedef long long ll;

void solve(){
    ll n{}, m{};
    cin >> n >> m;

    for(ll i{min(n, m)}; i; --i){
        if(n % i == 0 and m % i == 0){
            cout << (n / i) * (m / i) << '\n';
            break;
        }
    }
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
