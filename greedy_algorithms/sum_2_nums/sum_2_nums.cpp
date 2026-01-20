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
ll sum_dig(ll x){
	ll s=0;
	while(x>0){
		s+=(x%10);
		x/=10;
	}
	return s;

}

void solve() {
	ll n; cin >> n;
	if(n==1){
		cout << 1 <<" " << 0 <<endl;
		return;
	}
	if(n%2==0){
		cout << n/2 << " " << n/2 <<endl;
		return;
	}
	for(ll i=1 ; i<10;i++){
		if(sum_dig(n-i)==i || sum_dig(n-i)==(i+1) || sum_dig(n-i)==(i-1)){
			cout << i << " " << n-i << endl;
			return;
		}
	}
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
