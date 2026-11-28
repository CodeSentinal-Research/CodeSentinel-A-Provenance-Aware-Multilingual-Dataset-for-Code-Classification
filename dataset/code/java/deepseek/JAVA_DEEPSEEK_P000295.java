import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        System.out.println(myAtoi(str));
    }

    public static int myAtoi(String s) {
        if (s.isEmpty()) {
            return 0;
        }

        int i = 0;
        int sign = 1;
        int result = 0;

        // Handle leading whitespaces
        while (i < s.length() && s.charAt(i) == ' ') {
            i++;
        }

        // Handle sign
        if (i < s.length() && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            if (s.charAt(i) == '-') {
                sign = -1;
           }
            i++;
        }

        // Convert digits to integer
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            int digit = Character.getNumericValue(s.charAt(i));

            // Check for overflow
            if (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && digit > Integer.MAX_VALUE % 10)) {
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
}
