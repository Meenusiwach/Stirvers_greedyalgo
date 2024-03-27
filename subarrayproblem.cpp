#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        if (k <= 1) return 0; // If k <= 1, no subarray can have a product less than k
        
        int count = 0;
        int product = 1;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right];

            // Move the left pointer until the product is less than k
            while (product >= k) {
                product /= nums[left];
                left++;
            }

            // Count the number of subarrays that satisfy the condition
            count += right - left + 1;
        }

        return count;
    }
};
