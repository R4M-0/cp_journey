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
const int MAXN = 200000;

vector<int> primes;

void sieve() {
    vector<bool> is_prime(MAXN + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            if ((ll)i * i <= MAXN)
                for (int j = i * i; j <= MAXN; j += i)
                    is_prime[j] = false;
        }
    }
}
void solve() {
	ll d;
        cin >> d;
        ll p = 0, q = 0;
        for (int x : primes) {
            if (x >= d + 1) {
                p = x;
                break;
            }
        }
        for (int x : primes) {
            if (x >= p + d) {
                q = x;
                break;
            }
        }
        cout << p * q << '\n';
}


int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    sieve();
    cin >> t;
    while (t--) {
        solve();
       // cout << '\n';
    }
    return 0;
}
