#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0) ; cin.tie(0) ;
typedef long long ll ;
using namespace std ;

#define p first
#define w second

void solve(){
    int len, w;
    double value{};
    cin >> len >> w;

    pair<int, int> arr[len];
    for (int i{}; i < len; ++i)
        cin >> arr[i].p >> arr[i].w;
    sort(arr, arr + len, [](auto n1, auto n2){
        return ((double)n1.p / n1.w) > ((double)n2.p / n2.w);
    });

    for (int i{}; i < len; ++i){

        if (arr[i].w <= w){
            w -= arr[i].w;
            value += arr[i].p;
        }
        else{
            value += arr[i].p * ((double)w / (double)arr[i].w);
            break;
        }   
    }
    printf("%.2f", value);
}

int main(){
    IO
    solve() ;
}