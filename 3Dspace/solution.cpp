#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0) ; cin.tie(0) ;
typedef long long ll ;
using namespace std ;

const int MAX_SIZE = 50;
bool cube[MAX_SIZE][MAX_SIZE][MAX_SIZE]{}, vis[MAX_SIZE][MAX_SIZE][MAX_SIZE]{};
const vector<tuple<int,int,int>> directions = {
    {1, 0, 0}, {-1, 0, 0}, 
    {0, 1, 0}, {0, -1, 0},
    {0, 0, 1}, {0, 0, -1}
};

int N = 0;

int flood_fill(int x, int y, int z) {
    if (x < 0 or y < 0 or z < 0 or x > N or y > N or z > N ) return 0;
    if (vis[x][y][z] or !cube[x][y][z]) return 0;

    vis[x][y][z] = true;

    int ans = 1;
    for (auto &[dx, dy, dz]: directions) ans += flood_fill(x+dx, y+dy, z+dz);
    return ans;
}

void solve() {
    cin >> N;
    char c;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cin >> c;
                cube[i][j][k] = (c == '.') ? false : true;
                vis[i][j][k] = false;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (!vis[i][j][k] && cube[i][j][k]) 
                    ans = max(ans, flood_fill(i, j, k));
            }
        }
    }

    cout << ans << endl;
}
 

int main(){
    IO
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}