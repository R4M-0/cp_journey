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

void bfs(vector<vll> &graph, vector<bool> &vis, vll &ans, vll &vals) {
 
  queue<pll> q;
  q.push({0LL, 0LL});
  while (!q.empty()) {
    pll curr = q.front();
    q.pop();
    // cout << "curr: " << curr.first << ", depth: " << curr.second << endl;
    ll node = curr.first;
    ll depth = curr.second;
    vis[node] = true;
    ans[vals[node]] = max(depth, ans[vals[node]]);
    for (ll nd : graph[node]) {
      if (!vis[nd]) {
        vis[nd] = true;
        q.push({nd, depth + 1});
      }
    }
  }
}
 
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
 
  vll ans(k + 1, 0);
  vll vals(n);
  cin >> vals;
  vector<bool> vis(n, false);
 
  vector<vll> graph(n);
  for (ll i = 0; i < m; ++i) {
    ll a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
 
  bfs(graph, vis, ans, vals);
  for (ll i = 1; i <= k; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
