
import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static List<List<String>> partition(String str) {
        List<List<String>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), str, 0);
        return result;
    }

    private static void backtrack(List<List<String>> result, List<String> currentList, String str, int start) {
        if (start == str.length()) {
            result.add(new ArrayList<>(currentList));
            return;
        }

        for (int end = start + 1; end <= str.length(); end++) {
            String substring = str.substring(start, end);
            if (isPalindrome(substring)) {
                currentList.add(substring);
                backtrack(result, currentList, str, end);
                currentList.remove(currentList.size() - 1);
            }
        }
    }

    private static boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    
}
