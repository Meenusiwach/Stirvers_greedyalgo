#include <vector>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Remove negative numbers and zeros from the array
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0) {
                nums[i] = n + 1; // Replace negative numbers and zeros with a number outside the range [1, n]
            }
        }
        
        // Step 2: Mark numbers as visited by negating the value at corresponding index
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        
        // Step 3: Find the first positive number that is not marked as visited
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1; // Found the smallest positive integer missing
            }
        }
        
        // Step 4: If all positive integers in the range [1, n] are present, return n + 1
        return n + 1;
    }
};
