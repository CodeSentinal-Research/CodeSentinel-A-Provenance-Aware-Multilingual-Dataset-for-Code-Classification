import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String expression = scanner.nextLine();
        System.out.println(calculate(expression));
    }

    private static int calculate(String s) {
        int len = s.length();
        if (len == 0) return 0;

        int num = 0;
        int lastNum = 0;
        int res = 0;
        char lastSign = '+';

        for (int i = 0; i < len; i++) {
            if (Character.isDigit(s.charAt(i))) {
                num = num * 10 + s.charAt(i) - '0';
            }

            if ((s.charAt(i) < '0' || s.charAt(i) > '9') && s.charAt(i) != ' ' || i == len - 1) {
                if (lastSign == '+') {
                    res += lastNum;
                    lastNum = num;
                } else if (lastSign == '-') {
                    res += lastNum;
                    lastNum = -num;
                } else if (lastSign == '*') {
                    lastNum = lastNum * num;
                } else if (lastSign == '/') {
                    lastNum = lastNum / num;
                }

                num = 0;
                lastSign = s.charAt(i);
            }
        }

        return res + lastNum;
    }
}
