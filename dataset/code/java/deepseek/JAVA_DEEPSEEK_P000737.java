import java.util.*;

public class Main {
    public static List<Integer> diffWaysToCompute(String expression) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                String s1 = expression.substring(0, i);
                String s2 = expression.substring(i + 1);
                List<Integer> part1 = diffWaysToCompute(s1);
                List<Integer> part2 = diffWaysToCompute(s2);
                for (int p1 : part1) {
                    for (int p2 : part2) {
                        switch (c) {
                            case '+':
                                res.add(p1 + p2);
                                break;
                            case '-':
                                res.add(p1 - p2);
                                break;
                            case '*':
                                res.add(p1 * p2);
                                break;
                        }
                    }
                }
            }
        }
        if (res.isEmpty()) {
            res.add(Integer.valueOf(expression));
        }
        return res;
    }

    public static void main(String[] args) {
        List<Integer> res = diffWaysToCompute("2-1-1");
        for (int i : res) {
            System.out.println(i);
        }
    }
}
