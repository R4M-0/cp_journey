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
    for (auto &x : v) in >> x;
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
        if (e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}

ll sum(ll k){
    return k * (k + 1) / 2;
}

typedef __int128 lll;

lll digit_sum(ll n) {
    if (n <= 0) return 0;
    lll res = 0;
    ll p = 1; 
    while (p <= n) {
        ll higher = n / (p * 10); 
        ll cur = (n / p) % 10;    
        ll lower = n % p;         
        res += (lll)higher * 45 * p;
        res += (lll)cur * (cur - 1) / 2 * p;
        res += (lll)cur * (lower + 1);
        
        p *= 10;
    }
    return res;
}

ll total_digits(ll n) {
    if (n <= 0) return 0;
    ll res = 0;
    ll p = 1;
    int d = 1;
    while (p * 10 <= n) {
        res += (ll)d * p * 9;
        p *= 10;
        d++;
    }
    res += (ll)d * (n - p + 1);
    return res;
}
void solve(){
        ll k;
        cin >> k;
        
        ll lo = 1, hi = 1e15;
        while(lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if(total_digits(mid) <= k) lo = mid;
            else hi = mid - 1;
        }
        ll n = lo;
        ll used = total_digits(n);
        
        lll ans = digit_sum(n);
        
        ll rem = k - used;
        if(rem > 0) {
            string s = to_string(n + 1);
            for(int i = 0; i < rem; i++) ans += s[i] - '0';
        }
        
        lll val = ans;
        if(val == 0) { cout << 0; }
        else {
            string out;
            while(val > 0) { out += ('0' + (int)(val % 10)); val /= 10; }
            reverse(out.begin(), out.end());
            cout << out;
        }
        cout << '\n';
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
