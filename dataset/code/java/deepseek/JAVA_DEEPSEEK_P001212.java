import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String expression = scanner.nextLine();
        System.out.println(countWays(expression, 0, expression.length() - 1));
    }

    private static int countWays(String expression, int start, int end) {
        if (start > end) {
            return 0;
        }

        if (start == end) {
            return expression.charAt(start) == 'T' ? 1 : 0;
        }

        int count = 0;
        for (int i = start + 1; i <= end; i += 2) {
            char op = expression.charAt(start);
            char left = expression.charAt(start + 1);
            char right = expression.charAt(i + 1);

            if (op == '|') {
                if (left == 'T' && right == 'T') {
                    count += countWays(expression, start + 2, i - 1);
                } else if (left == 'F' && right == 'F') {
                    count += countWays(expression, start + 2, i - 1);
                }
            } else if (op == '^') {
                if (left == 'F' && right == 'T') {
                    count += countWays(expression, start + 2, i - 1);
                } else if (left == 'T' && right == 'F') {
                    count += countWays(expression, start + 2, i - 1);
                }
            }
        }

        return count;
    }
}
