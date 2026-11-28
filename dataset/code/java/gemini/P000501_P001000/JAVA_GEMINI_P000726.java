import java.util.*;
public class Solution {
    static List<String> diffWays(String expr) {
        List<String> res = new ArrayList<>();
        for (int i = 0; i < expr.length(); i++) {
            char c = expr.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                List<String> left = diffWays(expr.substring(0, i));
                List<String> right = diffWays(expr.substring(i + 1));
                for (String l : left) {
                    for (String r : right) {
                        res.add("(" + l + c + r + ")");
                    }
                }
            }
        }
        if (res.isEmpty()) res.add(expr);
        return res;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String expr = scanner.next();
            List<String> res = diffWays(expr);
            TreeSet<String> set = new TreeSet<>(res);
            for (String s : set) System.out.println(s);
        }
    }
}