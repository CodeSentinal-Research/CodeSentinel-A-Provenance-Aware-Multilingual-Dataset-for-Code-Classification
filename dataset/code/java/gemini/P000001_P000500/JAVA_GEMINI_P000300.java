import java.util.*;

public class Solution {
    private static final String[] MAPPING = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    private static void backtrack(String digits, int index, StringBuilder current, List<String> res) {
        if (index == digits.length()) {
            res.add(current.toString());
            return;
        }
        String letters = MAPPING[digits.charAt(index) - '0'];
        for (char c : letters.toCharArray()) {
            current.append(c);
            backtrack(digits, index + 1, current, res);
            current.deleteCharAt(current.length() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String digits = scanner.next();
            List<String> res = new ArrayList<>();
            if (!digits.isEmpty()) {
                backtrack(digits, 0, new StringBuilder(), res);
            }
            for (String s : res) {
                System.out.println(s);
            }
        }
    }
}