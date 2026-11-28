import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();

        generateParentheses(n, n, "");
    }

    private static void generateParentheses(int left, int right, String str) {
        if (left == 0 && right == 0) {
            System.out.println(str);
            return;
        }

        if (left < right) {
            generateParentheses(left + 1, right, str + "(");
        }

        if (right < left) {
            generateParentheses(left, right + 1, str + ")");
        }
    }
}
