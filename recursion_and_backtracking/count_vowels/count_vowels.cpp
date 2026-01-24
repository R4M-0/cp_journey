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

ll vowels(const string& s, int n){
    if (n < 0) return 0;
    return (s[n]=='a'||s[n]=='e'||s[n]=='i'||s[n]=='o'||s[n]=='u')
           + vowels(s, n-1);
}

void solve() {
    string s;
    getline(cin, s);

    if (s.empty()) {
        cout << 0 << endl;
        return;
    }

    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c){ return tolower(c); });

    cout << vowels(s, s.length() - 1) << endl;
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
