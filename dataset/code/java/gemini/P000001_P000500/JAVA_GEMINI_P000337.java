import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int ones = 0;
            for (char c : s.toCharArray()) if (c == '1') ones++;
            int maxScore = 0, zeros = 0;
            for (int i = 0; i < s.length() - 1; i++) {
                if (s.charAt(i) == '0') zeros++;
                else ones--;
                maxScore = Math.max(maxScore, zeros + ones);
            }
            System.out.println(maxScore);
        }
    }
}