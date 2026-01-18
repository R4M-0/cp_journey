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
	ll n, k; cin >> n >> k;
	vll w(k, 0);

	ll d = 0;

	for (ll i=0; i<n; ++i){
		ll c = 1;
		for (ll j=0; j<k; ++j){
			ll x; cin >> x;
			w[j] += x;

			c &= x;
		}
		if (c) d++;
	}

	for (ll j=0; j<k; ++j){
		if (w[j]-d > (n+1-d)/2){
			d++;
		}
	}
	cout << ((n > 0)?"YES\n": "NO\n");
}

int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // cout << '\n';
    }
    return 0;
}
