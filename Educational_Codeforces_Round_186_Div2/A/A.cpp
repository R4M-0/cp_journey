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
const int INF = 1e9;

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

int main() {
    MA9ROUNA_KADHEBA	
    int t;
    cin >> t;

    string pattern = "2025";
    vector<char> alpha = {'0','2','5','6'};

    vector<int> pi(4);
    for (int i = 1; i < 4; i++) {
        int j = pi[i-1];
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j-1];
        if (pattern[i] == pattern[j]) j++;
        pi[i] = j;
    }

    int go[5][4];
    for (int s = 0; s < 5; s++) {
        for (int c = 0; c < 4; c++) {
            char ch = alpha[c];
            int j = s;
            while (j > 0 && (j == 4 || pattern[j] != ch))
                j = pi[j-1];
            if (j < 4 && pattern[j] == ch) j++;
            go[s][c] = j;
        }
    }

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int costA = INF;
        for (int i = 0; i + 3 < n; i++) {
            string target = "2026";
            int diff = 0;
            for (int j = 0; j < 4; j++)
                if (s[i+j] != target[j]) diff++;
            costA = min(costA, diff);
        }

        vector<vector<int>> dp(n+1, vector<int>(5, INF));
        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int st = 0; st < 4; st++) {
                if (dp[i][st] == INF) continue;
                for (int c = 0; c < 4; c++) {
                    int nst = go[st][c];
                    if (nst == 4) continue; 
                    int cost = dp[i][st] + (s[i] != alpha[c]);
                    dp[i+1][nst] = min(dp[i+1][nst], cost);
                }
            }
        }

        int costB = INF;
        for (int st = 0; st < 4; st++)
            costB = min(costB, dp[n][st]);

        cout << min(costA, costB) << "\n";
    }

    return 0;
}

