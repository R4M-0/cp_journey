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
	ll n,k;
	cin >> n >>k;
	vector<vll> v;
	for(ll i=0 ; i<n; i++){
		vll v1(k);
		for(ll j=0; j<k ; j++){
			cin >> v1[j];
		}
		v.push_back(v1);
	}
	ll mi=1e18;
	for (ll i=0; i<k ; i++){
		ll cnt=0;
		for(ll j=0; j<n; j++){
			if(v[j][i]==0) cnt++;
		}
		mi=min(mi,cnt);
	}
	if(n-mi<=((n+1)/2)) cout << "YES" << endl;
	else cout << "NO"<< endl;
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
