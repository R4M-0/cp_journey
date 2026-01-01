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
	ll n; cin >> n;
	vll v(n-1);
	for (ll i = 0; i < n-1 ; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for(ll i = 1 ; i< n ; i++){
		if (v[i-1]!= i){
			cout << i << endl;
			return;
		}
	}

	cout << n << endl;
}

int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
        //cout << '\n';
    }
    return 0;
}
