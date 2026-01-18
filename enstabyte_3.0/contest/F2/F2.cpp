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
	ll n,k; cin >> n >>k;
	set<ll>v; v.insert(0);
	for(ll i = 0 ; i< n ; i++){
		ll s=0;
		for(ll j=0; j<k ; j++){
			ll x;
			cin >> x;
			s+=(((1<<(k-j-1))*x));
		}
		v.insert(s);
	}
	ll sum=0, cnt=0;
	for(auto x:v){
		if(sum<=(1<<k-1)) {sum+=x; cnt++;}
	}
	if(cnt==1 && (sum!=0)){
		cout << "NO" << endl;
		return;
	}
	if(sum>((1<<k)-1)){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
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
