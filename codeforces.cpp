#include <bits/stdc++.h>
#define f(i, n) for(long long i = 0; i < n; ++i)
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long tc = 1;
    cin >> tc;
    f(T, tc){
        long long  n, m, k;
        cin >> n >> m >> k;

        vector<long long> leftCoins(n);
        vector<long long> rightCoins(m);

        for (long long i = 0; i < n; ++i) {
            cin >> leftCoins[i];
        }

        for (long long i = 0; i < m; ++i) {
            cin >> rightCoins[i];
        }-

        sort(leftCoins.begin(), leftCoins.end());
        sort(rightCoins.begin(), rightCoins.end(), greater<long long>());

        long long count = 0;
        long long j = 0;

        for (long long i = 0; i < n; ++i) {
            for(long long j=0;j<m;j++){
            
            if(leftCoins[i]+rightCoins[j] <= k)count ++;
            }
        }

        cout << count << endl;
        }
    
    return 0;
}
