
import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int romanToInt(String s) {
        // Create a map to store the values of each Roman numeral
        Map<Character, Integer> romanValues = new HashMap<>();
        romanValues.put('I', 1);
        romanValues.put('V', 5);
        romanValues.put('X', 10);
        romanValues.put('L', 50);
        romanValues.put('C', 100);
        romanValues.put('D', 500);
        romanValues.put('M', 1000);

        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            int currentValue = romanValues.get(s.charAt(i));

            // Check if the next Roman numeral is greater, then subtract
            if (i < s.length() - 1 && currentValue < romanValues.get(s.charAt(i + 1))) {
                result -= currentValue;
            } else {
                result += currentValue;
            }
        }

        return result;
    }

    
}
