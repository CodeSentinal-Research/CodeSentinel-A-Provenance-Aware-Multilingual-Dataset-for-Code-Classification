import java.util.*;
public class Solution {
    static String process(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == '#') {
                if (sb.length() > 0) sb.deleteCharAt(sb.length() - 1);
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            String t = scanner.hasNext() ? scanner.next() : "";
            System.out.println(process(s).equals(process(t)) ? "true" : "false");
        }
    }
}