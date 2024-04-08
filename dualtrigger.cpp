#include <iostream>
#include <string> // Include the string library

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        // Iterate over the characters of the string
        for (int i = 0; i < s.size() - 1; i++) {
            // Check if 'i' and 'i+1' characters form the substring "it"
            if (s[i] == 'i' && s[i + 1] == 't') {
                cout << "YES" << endl;
                break;
            }
        }
        // If the loop completes without finding "it", print "NO"
        if (s.find("it") == string::npos) {
            cout << "NO" << endl;
        }
    }

    return 0;
}
