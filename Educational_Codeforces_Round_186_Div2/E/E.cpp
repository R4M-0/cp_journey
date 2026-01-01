#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define vll vector<ll>
#define all(v) v.begin(), v.end()

#define MA9ROUNA_KADHEBA                       \
    ios_base::sync_with_stdio(false);          \
    cin.tie(NULL);                             \
    cout.tie(NULL);

struct Friend {
    int id;
    int x;
    ll y;
    ll z;
    ll diff; 
};

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vll a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(all(a));

    vector<Friend> friends(n);
    ll sum_y = 0;
    for (int i = 0; i < n; i++) {
        friends[i].id = i;
        cin >> friends[i].x >> friends[i].y >> friends[i].z;
        friends[i].diff = friends[i].z - friends[i].y;
        sum_y += friends[i].y;
    }
    ll rem_k = k - sum_y;

    sort(friends.begin(), friends.end(), [](const Friend& a, const Friend& b) {
        return a.x < b.x;
    });
    priority_queue<pair<ll, int>> pq;
    vector<bool> is_boxed(n, false);
    int friend_idx = 0;

    for (int i = 0; i < m; i++) {
        while (friend_idx < n && friends[friend_idx].x <= a[i]) {
            pq.push({friends[friend_idx].diff, friends[friend_idx].id});
            friend_idx++;
        }
        if (!pq.empty()) {
            pair<ll, int> top = pq.top();
            pq.pop();
            is_boxed[top.second] = true;
        }
    }

    vll final_costs;
    for (int i = 0; i < n; i++) {
        if (is_boxed[friends[i].id]) {
            final_costs.push_back(0);
        } else {
            final_costs.push_back(friends[i].diff);
        }
    }

    sort(all(final_costs));
    int happy_count = 0;
    for (ll cost : final_costs) {
        if (rem_k >= cost) {
            rem_k -= cost;
            happy_count++;
        } else {
            break;
        }
    }
    cout << happy_count << "\n";
}

int main() {
    MA9ROUNA_KADHEBA
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
