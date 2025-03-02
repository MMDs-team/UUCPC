#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

typedef long long ll;

void solve(){
    ll n{}, k{};
    cin >> n >> k;

    ll len{1 << n}, a[len]{}, idx[len]{};
    for(ll i{}; i < len; ++i){
        cin >> a[i];
        idx[i] = i + 1;
    }

    while(k--){
        for(ll i{}; i < len; i += 2){
            if(a[i] >= a[i ^ 1]) a[i >> 1] = a[i], idx[i >> 1] = idx[i];
            else a[i >> 1] = a[i ^ 1], idx[i >> 1] = idx[i ^ 1];
        }
        len >>= 1;
    }

    cout << len << '\n';
    for(ll i{}; i < len; ++i) cout << idx[i] << ' ';
    cout << '\n';
}

int main(){
    IO

    ll tc{1ll};
    // cin >> tc;
    while(tc--) solve();
    
    return 0;
}
