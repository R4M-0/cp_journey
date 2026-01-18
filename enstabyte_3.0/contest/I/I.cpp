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
	ll n, a, b;
	cin >> n >> a >> b;

	map<pll, ll>m1, m2;

	for(ll i = 1; i<=3; ++i){
		for(ll j = 1; j<=3; ++j){
			ll x; cin >> x;
			m1[{i, j}] = x;
		}
	}
	for(ll i = 1; i<=3; ++i){
		for(ll j = 1; j<=3; ++j){
			ll x; cin >> x;
			m2[{i, j}] = x;
		}
	}

	ll pt_a = 0, pt_b = 0;
	while(n--){
		if(a > b || (b == 1 && a == 3)){
			pt_a++;
		} else if (a != b){
			pt_b++;
		}

		ll next_a = m1[{a, b}];
		ll next_b = m2[{a, b}];

		a = next_a;
		b = next_b;
	}
	cout << pt_a << " " << pt_b << endl;
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
