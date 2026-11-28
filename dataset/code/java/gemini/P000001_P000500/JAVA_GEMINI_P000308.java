import java.util.*;

public class Solution {
    private static Map<String, List<Integer>> memo = new HashMap<>();

    private static List<Integer> diffWaysToCompute(String expr) {
        if (memo.containsKey(expr)) return memo.get(expr);
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < expr.length(); i++) {
            char c = expr.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                List<Integer> left = diffWaysToCompute(expr.substring(0, i));
                List<Integer> right = diffWaysToCompute(expr.substring(i + 1));
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
        memo.put(expr, res);
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            List<Integer> res = diffWaysToCompute(scanner.next());
            for (int v : res) {
                System.out.println(v);
            }
        }
    }
}