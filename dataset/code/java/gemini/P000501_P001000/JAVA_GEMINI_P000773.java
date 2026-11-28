import java.util.*;
public class Solution {
    static Map<Long, Long> solve(String expr, int i, int j) {
        if (i == j) {
            Map<Long, Long> base = new HashMap<>();
            base.put((long)(expr.charAt(i) - '0'), 1L);
            return base;
        }
        Map<Long, Long> res = new HashMap<>();
        for (int k = i + 1; k < j; k += 2) {
            char op = expr.charAt(k);
            Map<Long, Long> left = solve(expr, i, k - 1);
            Map<Long, Long> right = solve(expr, k + 1, j);
            for (var l : left.entrySet()) {
                for (var r : right.entrySet()) {
                    long v = 0;
                    if (op == '+') v = l.getKey() + r.getKey();
                    else if (op == '-') v = l.getKey() - r.getKey();
                    else if (op == '*') v = l.getKey() * r.getKey();
                    res.put(v, res.getOrDefault(v, 0L) + l.getValue() * r.getValue());
                }
            }
        }
        return res;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String expr = scanner.next();
            Map<Long, Long> res = solve(expr, 0, expr.length() - 1);
            long maxV = Collections.max(res.keySet());
            System.out.println(res.get(maxV));
        }
    }
}