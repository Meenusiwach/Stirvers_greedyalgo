#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// Caesar cipher encryption function
string encryptString(string str, int shift) {
    string result = "";
    for (char& ch : str) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base + shift) % 26 + base;
        }
        result += ch;
    }
    return result;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    auto check = [&](int x) {
        int res = 0;
        auto dfs = [&](auto self, int v, int f) -> int {
            int sz = 1;
            for (int u : adj[v]) {
                if (u == f) {
                    continue;
                }
                sz += self(self, u, v);
            }
            if (sz >= x && f != v) {
                ++res, sz = 0;
            }
            return sz;
        };
        int t = dfs(dfs, 0, 0);
        return (res > k || (t >= x && res == k) ? true : false);
    };
    int low = 1, high = n / (k + 1) + 1;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    int ans = low;
    
    // Encrypt the result string using Caesar cipher with shift value k
    string encrypted_ans = encryptString(to_string(ans), k);
    cout << encrypted_ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
