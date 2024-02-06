
public class Solution {
    public static double myPow(double x, int n) {
        // Base case: x^0 = 1
        if (n == 0) {
            return 1.0;
        }

        // Handling negative power
        if (n < 0) {
            x = 1 / x;
            // Avoiding overflow when n is Integer.MIN_VALUE
            if (n == Integer.MIN_VALUE) {
                x *= x;
                n++;
            }
            n = -n;
        }

        double result = 1.0;
        double currentProduct = x;

        // Exponentiation by squaring
        while (n > 0) {
            if (n % 2 == 1) {
                result *= currentProduct;
            }
            currentProduct *= currentProduct;
            n /= 2;
        }

        return result;
    }
}
