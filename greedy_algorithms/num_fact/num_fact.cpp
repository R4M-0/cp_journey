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

#define mp make_pair
pair<int, int> s[110];
int d[110];

void solve() {
	int n, l = 0, i, c;
	cin >> n;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			c = 0;
			while (n % i == 0) c++, n /= i;
			s[++l] = make_pair(c, i);
		}
	}
	if (n != 1) s[++l] = make_pair(1, n);
	sort(s + 1, s + l + 1), d[l + 1] = 1;
	for (i = l; i >= 1; i--) d[i] = d[i + 1] * s[i].second;
	int ans = 0;
	for (i = 1; i <= l; i++) if (s[i].first != s[i - 1].first) ans += d[i] * (s[i].first - s[i - 1].first);
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
