#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, INT_MAX - 1);

        // Base case: 0 coins needed to make change for 0 amount
        dp[0] = 0;

        // Dynamic programming bottom-up approach
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }

        return (dp[amount] == INT_MAX - 1) ? -1 : dp[amount];
    }
};
