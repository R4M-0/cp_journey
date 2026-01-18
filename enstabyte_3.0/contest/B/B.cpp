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

void solve() {
	ll n; cin >> n;
	string s;
	getline(cin, s);
	getline(cin, s);
	vll v, ss;
	ll cnt = 0;
	ll spaces = 0;
	for(ll i=0; i<s.length(); i++){
		if(s[i]==' ' && cnt==0) {
			spaces++;
			continue;
		}
		if(s[i]!='.' && s[i]!='!' && s[i]!='?') cnt++;
		else{
			//cout << i << " "<< cnt << endl;
			v.push_back(cnt+1);
			ss.push_back(spaces);
			cnt=0;
			spaces = 0;
			continue;
		}
		if(cnt>=n) {
			cout <<"Impossible" << endl; return;
		}
	}
	if (s[s.length()-1] != '.' && s[s.length()-1] != '!' && s[s.length()-1] != '?'){
		v.push_back(cnt);
	}
	ll sp = v.size();
	//cout << sp << endl;
	for(ll i = 0; i<v.size()-1; ){
		ll skip = 1;
		ll curr = v[i];
		for(ll j = i+1; j < v.size(); j++){
			if (curr + v[j] + ss[i] <= n){
				//cout << "c: " << curr << "new: " << v[j] << endl;
				skip++;
				sp--;
			}else break;
		}
		i += skip;
	}
	cout << sp << endl;

}

int main() {
    // MA9ROUNA_KADHEBA
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // cout << '\n';
    }
    return 0;
}
