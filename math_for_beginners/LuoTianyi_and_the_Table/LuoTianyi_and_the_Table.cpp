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
	ll n,m;
	cin>>n>>m;
	ll a[n*m];
	for(int i=1;i<=n*m;++i)cin>>a[i];
	sort(a+1,a+n*m+1);
	if(n>m)swap(n,m);
	ll ans1=(n*m-1)*(a[n*m])-a[1]*(n*(m-1))-a[2]*(n-1);
	ll ans2=a[n*m]*(n*(m-1))+a[n*m-1]*(n-1)-a[1]*(n*m-1);
	cout<<max(ans1,ans2)<<'\n';
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
