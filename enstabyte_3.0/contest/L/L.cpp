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
	ll n,t; cin >> n >>t;
	vector<pair<ld, ld>> v(n);
	for(ll i=0; i<n;i++){
		ld x, a; cin >> x >> a;
		v[i] = {x, a};
	}

	sort(all(v));
	if(n==1){
		cout << 2 << endl;
		return;
	}
	ll ans=2;
	for(ll i=1; i<n ;i++){
                ld tmp = abs(v[i-1].first+(v[i-1].second/2) - v[i].first+(v[i].second/2));
		if(tmp == t) ans++;
		if(tmp>t) ans+=2;
		if(tmp<t) ans+=0;
	}
	cout << ans << endl;

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
