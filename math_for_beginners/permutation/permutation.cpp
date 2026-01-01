#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define vll vector<ll>
#define pll pair<ll, ll>
#define endl '\n'
#define MA9ROUNA_KADHEBA                                                       \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);

const int MOD = 1000000007;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}
ll modpow(ll a, ll e, ll mod = MOD) {
    ll r = 1;
    while (e) {
        if (e & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}

void solve(){
    int n; 	
    cin >> n;
    vector<vector<int>>perm(n, vector<int>(n - 1));
    vector<int>p(n, 0);
    vector<int>cnt(n + 1, 0);
    for(int i = 0; i < n; i++){
        p[i] = i + 1;
        for(int j = 0; j < n - 1; j++){
            cin >> perm[i][j];
            if(j == 0) cnt[perm[i][j]]++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(cnt[i] == n - 1){
            p[0] = i;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(perm[i][0] != p[0]){
            for(int j = 0; j < n - 1; j++){
                p[j + 1] = perm[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++) cout << p[i] << ' ';
    cout << endl;

}

int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        // cout << '\n';
    }
    return 0;
}
