
public class Solution {
    public static int atoi(String str) {
        if (str == null || str.isEmpty()) {
            return 0;
        }

        int index = 0;
        int sign = 1;
        int result = 0;

        // Step 1: Discard leading whitespaces
        while (index < str.length() && str.charAt(index) == ' ') {
            index++;
        }

        // Step 2: Check for sign
        if (index < str.length() && (str.charAt(index) == '+' || str.charAt(index) == '-')) {
            sign = (str.charAt(index) == '-') ? -1 : 1;
            index++;
        }

        // Step 3: Read and accumulate digits
        while (index < str.length() && Character.isDigit(str.charAt(index))) {
            int digit = Character.getNumericValue(str.charAt(index));

            // Step 5: Check for overflow
            if (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && digit > 7)) {
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            result = result * 10 + digit;
            index++;
        }

        // Step 4: Adjust sign
        return result * sign;
    }
}


