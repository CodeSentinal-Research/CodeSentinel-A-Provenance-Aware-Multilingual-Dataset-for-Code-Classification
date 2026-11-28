import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            char[] s = scanner.next().toCharArray();
            for (int i = 1; i < s.length; i += 2) {
                s[i] = (char)(s[i - 1] + (s[i] - '0'));
            }
            System.out.println(new String(s));
        }
    }
}