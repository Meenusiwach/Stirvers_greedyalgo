
import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static List<String> generateString(int N) {
        List<String> result = new ArrayList<>();
        generateBinaryStrings("", N, result);
        return result;
    }

    private static void generateBinaryStrings(String current, int remaining, List<String> result) {
        if (remaining == 0) {
            result.add(current);
            return;
        }

        if (current.isEmpty() || current.charAt(current.length() - 1) == '0') {
            generateBinaryStrings(current + "0", remaining - 1, result);
            generateBinaryStrings(current + "1", remaining - 1, result);
        } else {
            generateBinaryStrings(current + "0", remaining - 1, result);
        }
    }

    
}
