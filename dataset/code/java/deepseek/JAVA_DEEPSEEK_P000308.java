import java.util.*;

public class Main {
    public static List<Integer> diffWaysToCompute(String input) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                String p1 = input.substring(0, i);
                String p2 = input.substring(i + 1);
                List<Integer> part1 = diffWaysToCompute(p1);
                List<Integer> part2 = diffWaysToCompute(p2);
                for (int n1 : part1) {
                    for (int n2 : part2) {
                        switch (c) {
                            case '+':
                                res.add(n1 + n2);
                                break;
                            case '-':
                                res.add(n1 - n2);
                                break;
                            case '*':
                                res.add(n1 * n2);
                                break;
                        }
                    }
                }
            }
        }
        if (res.isEmpty()) {
            res.add(Integer.valueOf(input));
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        List<Integer> result = diffWaysToCompute(input);
        for (int num : result) {
            System.out.println(num);
        }
    }
}
