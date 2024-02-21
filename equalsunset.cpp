#include <vector>
#include <numeric>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);

        // If the total sum is odd, it's not possible to partition the array into two equal sum subsets
        if (totalSum % 2 != 0) {
            return false;
        }

        int targetSum = totalSum / 2;
        int n = nums.size();

        // dp[i][j] is true if there is a subset of nums[0..i] with sum equal to j
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(targetSum + 1, false));

        // Base case: an empty subset can always have a sum of 0
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        // Dynamic programming bottom-up approach
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= targetSum; ++j) {
                // If the current element is greater than the target sum, skip it
                if (nums[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // Include the current element or exclude it
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][targetSum];
    }
};
