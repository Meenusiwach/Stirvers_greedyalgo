#include <iostream>
#include <vector>

using namespace std;

// Function to encrypt a string by shifting each character by a fixed number of positions
string encryptString(const string& str, int shift) {
    string encryptedStr = str;
    for (char& c : encryptedStr) {
        if (isalpha(c)) {
            if (isupper(c)) {
                c = 'A' + (c - 'A' + shift) % 26;
            } else {
                c = 'a' + (c - 'a' + shift) % 26;
            }
        }
    }
    return encryptedStr;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> src(n);
    int P = 0;
    for (int i = 0; i < n; ++i) {
        cin >> src[i];
        if (src[i] == x) {
            P = i;
        }
    }

    int l = 0;
    int r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;

        if (src[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << "1\n";
    cout << P + 1 << ' ' << l + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
