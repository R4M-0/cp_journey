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
        pair<int,int> arr[n + 1];
        for(int i = 1; i <= n; i++) cin >> arr[i].first, arr[i].second = i;
        sort(arr + 1, arr + n + 1);
        int nxt[n + 1];
        ll sum[n + 1];
        int ans[n + 1];
        nxt[0] = sum[0] = 0;
        for(int i = 1; i <= n; i++){
            if(nxt[i - 1] >= i){
                nxt[i] = nxt[i - 1];
                sum[i] = sum[i - 1];
            } else {
                sum[i] = sum[i - 1] + arr[i].first;
                nxt[i] = i;
                while(nxt[i] + 1 <= n && sum[i] >= arr[nxt[i] + 1].first){
                    nxt[i]++;
                    sum[i] += arr[nxt[i]].first;
                }
            }
            ans[arr[i].second] = nxt[i];
        }
        for(int i = 1; i <= n; i++) cout << ans[i] - 1 << " ";
}

int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
