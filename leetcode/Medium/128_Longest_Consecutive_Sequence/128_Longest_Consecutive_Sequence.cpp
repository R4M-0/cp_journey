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

int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0|| nums.size()==1) return nums.size();
        set<int> s;
        for (auto x : nums){
                s.insert(x);
        }
        int m=1,curr_m=1;
        for (auto x: s){
            if(s.find(x+1) != s.end()) {curr_m++; m=max(m,curr_m);}
            else curr_m=1;
        }
        return m;
    }

void solve() {
	int n; cin >> n;
	vector<int> nums(n);
	for(int &x: nums) cin >> x;
	cout << longestConsecutive(nums) << endl; 
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
