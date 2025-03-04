#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0) ; cin.tie(0) ;
typedef long long ll ;
using namespace std ;

void solve() {
    int n;
    ll c;
    cin >> n >> c;

    int s[n]{};
    
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        c -= 1LL * s[i] * s[i];
        sum += s[i];
    }
    c /= 4;
    
    ll lo = 0, hi = 1e9;
    while (lo < hi) {
        ll x = (lo + hi) / 2;
        if (__int128(n) * x * x + __int128(sum) * x < c) {
            lo = x + 1;
        } else {
            hi = x;
        }
    }
    
    cout << lo << '\n';
}
 

int main(){
    IO
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}