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

//---------------------------
vector<ll> sieve(ll n){
    vector<ll> sieve(n+1,0);
    vector<ll> primes;

    for(ll x=2;x<=n;x++){
        if(sieve[x] == 0){
            primes.push_back(x);
            for(ll u = x*2;u<=n;u+=x){
                sieve[u] = 1;
            }
        }
        
    }
    return primes;
}
//--------------------------
bool isPrime(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
//----------------------------
vector<ll> PrimeFactors(ll n){
    vector<ll> pf;
    while(n%2 == 0){
        pf.push_back(2);
        n = n/2;
    }
    for(int i=3;i<=sqrt(n);i+=2){
        while(n%i == 0){
            pf.push_back(i);
            n = n/i;
        }
    }
    if(n>1) pf.push_back(n);
    return pf;
}


void solve() {
    ll c1,c2,c3,c4,c5;
    cin >> c1 >> c2 >> c3 >> c4 >> c5;
    ll total = c1+c2+c3+c4+c5;
    if(total %5 == 0){
        if(total == 0){
            cout << -1;
            return;
        } 
        cout << total/5;
    }
    else cout << -1;
  

}




int main() {
    MA9ROUNA_KADHEBA
    #ifndef ONLINE_JUDGE
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
    #endif
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}

