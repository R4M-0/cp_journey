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
	vector<int> a(n);
	map<int, vector<int>> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		p[a[i]].push_back(i);
	}
	int ans = 0;
	set<int> ts;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) ts.insert(i);
	}
	while (!ts.empty()) {
		int i = *ts.begin();
		int x;
		if (a[i] > 0) {
			x = a[i];
		} else {
			x = a[i + 1];
		}
		for (int j: p[x]) {
			a[j] = 0;
			ts.erase(j - 1);
			ts.erase(j);
			if (j > 0 && a[j - 1] > a[j]) ts.insert(j - 1);
			if (j + 1 < n && a[j] > a[j + 1]) ts.insert(j);
		}
		ans++;
	}
	cout << ans << endl;
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
