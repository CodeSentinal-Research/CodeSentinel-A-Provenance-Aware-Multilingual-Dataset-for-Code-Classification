import java.util.*;
public class Solution {
    static List<Integer> diffWays(String expr) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < expr.length(); i++) {
            char c = expr.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                List<Integer> left = diffWays(expr.substring(0, i));
                List<Integer> right = diffWays(expr.substring(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') res.add(l + r);
                        else if (c == '-') res.add(l - r);
                        else if (c == '*') res.add(l * r);
                    }
                }
            }
        }
        if (res.isEmpty()) res.add(Integer.parseInt(expr));
        return res;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            List<Integer> res = diffWays(scanner.next());
            Collections.sort(res);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < res.size(); i++) {
                sb.append(res.get(i)).append(i + 1 == res.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}