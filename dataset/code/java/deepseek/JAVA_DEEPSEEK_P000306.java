import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String expression = scanner.nextLine();
        System.out.println(calculate(expression));
    }

    private static int calculate(String s) {
        int len = s.length();
        int num = 0;
        char sign = '+';
        int res = 0;
        int pre = 0;
        for(int i = 0; i < len; i++) {
            if(Character.isDigit(s.charAt(i))) {
                num = num * 10 + s.charAt(i) - '0';
            }
            if((i == len - 1 || !Character.isDigit(s.charAt(i + 1))) && (sign == '+' || sign == '-')) {
                res += pre;
                pre = sign == '+' ? num : -num;
            } else if(sign == '*') {
                pre *= num;
            } else if(sign == '/') {
                pre /= num;
            }
            if(i < len - 1 && (s.charAt(i + 1) == '+' || s.charAt(i + 1) == '-' || s.charAt(i + 1) == '*' || s.charAt(i + 1) == '/')) {
                sign = s.charAt(i + 1);
            }
            num = 0;
        }
        return res + pre;
    }
}
