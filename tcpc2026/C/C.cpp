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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int inc = 0; 
    int dec = 0; 

    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i+1]) inc++;
        if (a[i] < a[i+1]) dec++;
    }

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int i, x;
            cin >> i >> x;

            if (i > 1) {
                if (a[i-1] > a[i]) inc--;
                if (a[i-1] < a[i]) dec--;
            }
            if (i < n) {
                if (a[i] > a[i+1]) inc--;
                if (a[i] < a[i+1]) dec--;
            }

            a[i] = x;

            if (i > 1) {
                if (a[i-1] > a[i]) inc++;
                if (a[i-1] < a[i]) dec++;
            }
            if (i < n) {
                if (a[i] > a[i+1]) inc++;
                if (a[i] < a[i+1]) dec++;
            }
            
        } else if (type == 2) {
            if (inc == 0) cout << "YES\n";
            else cout << "NO\n";
            
        } else if (type == 3) {
            if (dec == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
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
