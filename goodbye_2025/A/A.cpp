#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        // Count the number of Y's in the string
        int y_count = 0;
        for (char c : s) {
            if (c == 'Y') {
                y_count++;
            }
        }
        
        // We can reduce to a single character if and only if
        // there is at most one Y in the string
        if (y_count <= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
