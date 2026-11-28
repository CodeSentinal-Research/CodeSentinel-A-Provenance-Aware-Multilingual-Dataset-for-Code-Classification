import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        if (isValidFibonacci(input)) {
            System.out.println(input);
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }

    private static boolean isValidFibonacci(String s) {
        // Check if the string can be split into three Fibonacci numbers
        int a = Integer.parseInt(s.substring(0, 1));
        int b = Integer.parseInt(s.substring(1, 2));
        int c = Integer.parseInt(s.substring(2, 3));
        if (a + b <= c || a + c <= b || b + c <= a) {
            return false;
        }

        // Check if the string can be split into three Fibonacci numbers with the same first digit
        for (int i = 0; i < s.length() - 2; i++) {
            a = b;
            b = c;
            c = Integer.parseInt(s.substring(i + 2, i + 3));
            if (a + b == c || a + c == b || b + c == a) {
                return true;
            }
        }

        // Check if the string can be split into three Fibonacci numbers with the same second digit
        for (int i = 0; i < s.length() - 1; i++) {
            a = b;
            b = Integer.parseInt(s.substring(i + 1, i + 2));
            c = Integer.parseInt(s.substring(i + 2, i + 3));
            if (a + b == c || a + c == b || b + c == a) {
                return true;
            }
        }

        // Check if the string can be split into three Fibonacci numbers with the same third digit
        for (int i = 0; i < s.length() - 1; i++) {
            a = Integer.parseInt(s.substring(i + 1, i + 2));
            b = Integer.parseInt(s.substring(i + 2, i + 3));
            c = Integer.parseInt(s.substring(i + 3, i + 4));
            if (a + b == c || a + c == b || b + c == a) {
                return true;
            }
        }

        return false;
    }
}
