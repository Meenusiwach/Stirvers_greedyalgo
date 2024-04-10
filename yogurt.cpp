#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;
    while (test) {
        int n, a, b;
        cin >> n >> a >> b;
        int sum = 0;
        if (2 * a >= b) {
            sum = (n / 2) * b + (n % 2) * a;
        } else {
            sum = n * a;
        }
        cout << sum << endl;
        test--;
    }
    return 0;
}
