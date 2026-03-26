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
const ll INF = 1e18;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)(v).size()

#define pb push_back
#define fi first
#define se second
#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define f(i, b) for (ll i = 0LL; i < (ll)(b); ++i)
#define fa(i, a, b) for (ll i = (a); i < (ll)(b); ++i)
#define rf(i, a, b) for (ll i = (a); i >= (ll)(b); --i)
#define each(a, x) for (auto &a : x)

template <typename T> istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        out << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    return out;
}

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
bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    string t;
    cin >> t;
    
    int max_v = 0;
    while ((max_v + 1) * (max_v + 1) + (max_v + 1) <= n) {
        max_v++;
    }
    vector<vector<vll>> dp(m + 1, vector<vll>(max_v + 1, vll(2, 0)));
    dp[0][0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        vector<vector<vll>> next_dp(m + 1, vector<vll>(max_v + 1, vll(2, 0)));
        
        for (int j = 0; j <= m; j++) {
            for (int v = 0; v <= max_v; v++) {
                for (int k = 0; k < 2; k++) {
                    ll ways = dp[j][v][k];
                    if (ways == 0) continue;
                    
                    if (j < m) {
                        char req = t[j];
                        bool req_vowel = is_vowel(req);
                        
                        if (k == 0 && v + 1 <= max_v) { 
                            if (req_vowel) {
                                next_dp[j + 1][v + 1][1] = (next_dp[j + 1][v + 1][1] + ways) % MOD;     
                                next_dp[j][v + 1][1] = (next_dp[j][v + 1][1] + ways * 4) % MOD;        
                            } else {
                                next_dp[j][v + 1][1] = (next_dp[j][v + 1][1] + ways * 5) % MOD;         
                            }
                        }
                        
                        if (!req_vowel) {
                            next_dp[j + 1][v][0] = (next_dp[j + 1][v][0] + ways) % MOD;                 
                            next_dp[j][v][0] = (next_dp[j][v][0] + ways * 20) % MOD;                    
                        } else {
                            next_dp[j][v][0] = (next_dp[j][v][0] + ways * 21) % MOD;                    
                        }
                    } else { 
                        if (k == 0 && v + 1 <= max_v) {
                            next_dp[m][v + 1][1] = (next_dp[m][v + 1][1] + ways * 5) % MOD;
                        }
                        next_dp[m][v][0] = (next_dp[m][v][0] + ways * 21) % MOD;
                    }
                }
            }
        }
        dp = next_dp;
    }
    
    ll ans = 0;
    for (int v = 0; v <= max_v; v++) {
        ans = (ans + dp[m][v][0]) % MOD;
        ans = (ans + dp[m][v][1]) % MOD;
    }
    
    cout << ans << "\n";
    
    return 0;
}
