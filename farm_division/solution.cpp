#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

typedef long long ll;

void solve(){
    ll n{}, m{};
    cin >> n >> m;

    ll g{__gcd(n, m)};
    cout << ((n / g) * (m / g)) << '\n';
}

int main(){
    IO

    ll tc{1ll};
    // cin >> tc;
    while(tc--) solve();
    
    return 0;
}
