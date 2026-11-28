import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            StringBuilder sb = new StringBuilder();
            for (char c : s.toCharArray()) {
                if (sb.length() > 0 && sb.charAt(sb.length() - 1) == c) {
                    sb.deleteCharAt(sb.length() - 1);
                } else {
                    sb.append(c);
                }
            }
            System.out.println(sb.toString());
        }
    }
}