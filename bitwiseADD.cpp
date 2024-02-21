
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        // Finding the common leftmost bits
        while (left < right) {
            left >>= 1;  // Right shift left operand
            right >>= 1; // Right shift right operand
            ++shift;     // Count the number of shifts
        }

        return left << shift; // Left shift the common bits back to the original position
    }
};
