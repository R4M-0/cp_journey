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
int LCS(vector<int>& firstArr,
        vector<int>& secondArr)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < firstArr.size(); i++) {
        mp[firstArr[i]] = i + 1;
    }
    vector<int> tempArr;
    for (int i = 0; i < secondArr.size(); i++) {
        if (mp.find(secondArr[i]) != mp.end()) {
            tempArr.push_back(mp[secondArr[i]]);
        }
    }
    vector<int> tail;
    tail.push_back(tempArr[0]);
    for (int i = 1; i < tempArr.size(); i++) {
        if (tempArr[i] > tail.back())
            tail.push_back(tempArr[i]);
        else if (tempArr[i] < tail[0])
            tail[0] = tempArr[i];
        else {
            auto it = lower_bound(tail.begin(),
                                  tail.end(),
                                  tempArr[i]);
            *it = tempArr[i];
        }
    }
    return (int)tail.size();
}

void solve() {
	ll n; cin >> n;
	vector<int> v9(n);
	cin >> v9;
	vector<int> v22(n);
	cin >> v22;
	cout << n - LCS(v9,v22) << endl;	
	
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
