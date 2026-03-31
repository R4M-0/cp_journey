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

void solve(){
    ll N, Y, W;
    cin >> N >> Y >> W;
    ll d = 3*N - Y - W;
    if(d < 0){
        cout << -1 << "\n";
        return;
    }
    ll rem_y = Y - d;
    ll rem_w = W - d;
    if(rem_y < 0 || rem_w < 0 || rem_y % 3 != 0 || rem_w % 3 != 0){
        cout << -1 << "\n";
        return;
    }
    ll wy = rem_y / 3;
    ll ww = rem_w / 3;
    if(d + wy + ww != N){
        cout << -1 << "\n";
        return;
    }
    string ans(N, '?');
    for(ll i = 0; i < d; i++) ans[i] = 'D';
    for(ll i = d; i < d + ww; i++) ans[i] = 'L';
    for(ll i = d + ww; i < N; i++) ans[i] = 'W';
    cout << ans;
    for(char c : ans){
    	if(c == 'W') cout << 'L';
    	else if(c == 'L') cout << 'W';
    	else cout << 'D';
    }
    cout << "\n";
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
