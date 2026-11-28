import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String expression = scanner.nextLine();
        Set<Integer> results = new TreeSet<>();
        backtrack(expression, 0, 0, 0, results);
        for (int result : results) {
            System.out.println(result);
        }
    }

    private static void backtrack(String expression, int index, long num, long result, Set<Integer> results) {
        if (index == expression.length()) {
            results.add((int) result);
            return;
        }
        if (expression.charAt(index) == '+') {
            backtrack(expression, index + 1, num + result, 0, results);
        } else if (expression.charAt(index) == '-') {
            backtrack(expression, index + 1, num - result, 0, results);
        } else if (expression.charAt(index) == '*') {
            backtrack(expression, index + 1, num * result, 0, results);
        } else {
            result = result * 10 + (expression.charAt(index) - '0');
            backtrack(expression, index + 1, num, result, results);
        }
    }
}
