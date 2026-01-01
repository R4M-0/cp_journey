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

ll digitProduct(ll num) {
    ll prod = 1;
    while (num > 0) {
        prod *= (num % 10);
        num /= 10;
    }
    return prod;
}

void solve() {
    ll n;
    cin >> n;
    ll maxProd = digitProduct(n);
    string s = to_string(n);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] > '0') {
            string temp = s;
            temp[i]--;
            for (int j = i + 1; j < temp.length(); j++) {
                temp[j] = '9';
            }
            if (temp[0] == '0') {
                if (temp.length() > 1) {
                    ll prod = 1;
                    for (int j = 0; j < temp.length() - 1; j++) {
                        prod *= 9;
                    }
                    maxProd = max(maxProd, prod);
                }
            } else {
                ll candidate = stoll(temp);
                maxProd = max(maxProd, digitProduct(candidate));
            }
        }
    }
    
    cout << maxProd << endl;
}

int main() {
    MA9ROUNA_KADHEBA
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
