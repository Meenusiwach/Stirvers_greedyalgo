#include <vector>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        std::vector<int> trustCounts(n + 1, 0); // Initialize trust counts for each person
        std::vector<int> trustedByCounts(n + 1, 0); // Initialize trusted-by counts for each person
        
        for (const auto& relation : trust) {
            int a = relation[0];
            int b = relation[1];
            trustCounts[a]++; // Increment trust count for person a
            trustedByCounts[b]++; // Increment trusted-by count for person b
        }
        
        for (int i = 1; i <= n; ++i) {
            // Check if person i satisfies both conditions
            if (trustCounts[i] == 0 && trustedByCounts[i] == n - 1) {
                return i; // Return the label of the town judge
            }
        }
        
        return -1; // If no town judge is found
    }
};
