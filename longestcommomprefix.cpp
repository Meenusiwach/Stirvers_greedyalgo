#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return ""; // Return an empty string if the array is empty
        }

        // Iterate through characters of the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            char currentChar = strs[0][i];

            // Compare with corresponding characters of other strings
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != currentChar) {
                    // If mismatch or end of string is reached, return the common prefix
                    return strs[0].substr(0, i);
                }
            }
        }

        // If all characters match, return the entire first string as the common prefix
        return strs[0];
    }
};
