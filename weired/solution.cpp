#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0) ; cin.tie(0) ;
typedef long long ll ;
using namespace std ;

void solve() {
    int n;
    cin >> n;
    
    while (true) {
        cout << n << ' ';
        if (n == 1) break;
        if (n % 2 == 0) n /= 2;
        else {
            n *= 3;
            n++;
        }
    }
    
}
 

int main(){
    IO
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}