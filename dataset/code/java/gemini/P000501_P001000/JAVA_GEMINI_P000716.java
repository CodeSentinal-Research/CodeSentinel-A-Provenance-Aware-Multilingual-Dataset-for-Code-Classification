import java.util.*;
public class Solution {
    static String[] pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    static void letterComb(String digits, int idx, String cur) {
        if (idx == digits.length()) {
            System.out.println(cur);
            return;
        }
        int d = digits.charAt(idx) - '0';
        for (char c : pad[d].toCharArray()) {
            letterComb(digits, idx + 1, cur + c);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            letterComb(scanner.next(), 0, "");
        }
    }
}