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
void solve() {
    ll n, k, q; 
    cin >> n >> k >> q;
    
    vll constraint_type(n, 0);
    
    for(ll i = 0; i < q; i++){
        ll c, l, r; 
        cin >> c >> l >> r;
        l--; r--; 
        
        if(c == 1){
            for(ll j = l; j <= r; j++){
                if(constraint_type[j] == 0) constraint_type[j] = 1;
                else if(constraint_type[j] == 2) constraint_type[j] = 3;
            }
        }
        else if(c == 2){
            for(ll j = l; j <= r; j++){
                if(constraint_type[j] == 0) constraint_type[j] = 2;
                else if(constraint_type[j] == 1) constraint_type[j] = 3;
            }
        }
    }
    vll v(n);
    ll mex_counter = 0;
    
    for(ll i = 0; i < n; i++){
        if(constraint_type[i] == 0){
            v[i] = 0;
        }
        else if(constraint_type[i] == 1){
            v[i] = k;
        }
        else if(constraint_type[i] == 2){
            v[i] = mex_counter % k;
            mex_counter++;
        }
        else if(constraint_type[i] == 3){
            v[i] = k + 1;
        }
    }
    
    for(ll i = 0; i < n; i++){
        cout << v[i];
        if(i < n-1) cout << " ";
    }
}

int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
