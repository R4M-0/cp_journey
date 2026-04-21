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

const int MOD = 998244353;
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
//f(i)=1 xor 2 xor 3..... xor i
//a xor a = 0
//a xor b = 0 maaneha a=b
// l xor .... xor r =0 maaneha f(r) xor f(l-1) = 0 maaneha f(r) = f(l-1) 
//khater f(r)= f(l-1) xor l xor l+1 xor ... xor r 
//donc f(r) xor f(l-1) = l xor .... xor r
//1<=l<=x<=r<=n
//p=l-1 => 0<=p<=x-1
//q=r => x<=q<=n
//donc lezem nalkaw (p,q) w f(p)=f(q)
//f(i) = i ken i%4=0
//f(i) = 1 ken i%4=1
//f(i)= i+1 ken i%4=2
//f(i) = 0 ken i%4=3
//donc f(i) tetaawed ken ki i%4==1 wala ==3
//donc juste nehseb larkam lkol li hakeka w nzid maahom i==0 
//donc hachti nalka Cnt_k(l,r) (kadeh mn aadad bin l w r li mod4 mteeou tji k)
//w k hne ya 0 ya 1 w l w r houma p w q 
// donc ans= Cnt_1(0,x-1)*Cnt_1(x,n) + Cnt_0(0,x-1)*Cnt_0(x,n)
// w nrajaa ans%MOD fellekher

ll getCnt(ll l, ll r, ll mod) {
    if (r < l) return 0;
    ll first = l + (mod - l % 4 + 4) % 4;
    if (first > r) return 0;
    return (r - first) / 4 + 1;
}

ll getZero(ll l, ll r) {
    if (r < l) return 0;
    ll res = 0;
    // 0 mawjoud donc nehsbou
    if (l <= 0 && 0 <= r) res++;
    res += getCnt(max(l, 1LL), r, 3);
    return res;
}

ll getOne(ll l, ll r) {
    if (r < l) return 0;
    return getCnt(l, r, 1);
}

void solve() {
    ll n, x;
    cin >> n >> x;
    ll p1 = getOne(0, x - 1);
    ll q1 = getOne(x, n);
    ll p0 = getZero(0, x - 1);
    ll q0 = getZero(x, n);
    ll ans = ((p1 % MOD) * (q1 % MOD) % MOD + (p0 % MOD) * (q0 % MOD) % MOD) % MOD;
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
