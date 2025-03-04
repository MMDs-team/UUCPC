#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0) ; cin.tie(0) ;
typedef long long ll ;
using namespace std ;

void solve() {
    
    int n,q,right,left;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];    
    int dp[n+1];
    dp[n] = -1;
    dp[n-1] = -1;
 
    for (int i = n-2; i >= 0; i--) {
        if (a[i] == a[i+1]) dp[i] = dp[i+1];
        else dp[i] = i+2;
    }   
    
    cin >> q;
    while (q--) {
        cin >> left >> right;
        if (dp[left-1] == -1 || dp[left-1] > right) cout << -1 << " " << -1 << endl;
        else cout << left << " " << dp[left-1] << endl;
    }
}
 

int main(){
    IO
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}