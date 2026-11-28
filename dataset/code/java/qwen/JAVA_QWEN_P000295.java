import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next().trim();
        
        int i = 0;
        int sign = 1;
        long result = 0;
        
        while (i < s.length() && s.charAt(i) == ' ') {
            i++;
        }
        
        if (i < s.length() && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            sign = (s.charAt(i) == '-') ? -1 : 1;
            i++;
        }
        
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            int digit = s.charAt(i) - '0';
            if (result > (Integer.MAX_VALUE - digit) / 10) {
                System.out.println(sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE);
                return;
            }
            result = result * 10 + digit;
            i++;
        }
        
        System.out.println((int)(result * sign));
    }
}
