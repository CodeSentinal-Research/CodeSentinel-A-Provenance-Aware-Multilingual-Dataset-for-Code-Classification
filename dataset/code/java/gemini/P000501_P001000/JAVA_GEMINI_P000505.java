import java.util.*;
public class Solution {
    static long calculate(String s) {
        Stack<Long> st = new Stack<>();
        long num = 0;
        char sign = '+';
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) num = num * 10 + (c - '0');
            if ((!Character.isDigit(c) && c != ' ') || i == s.length() - 1) {
                if (sign == '+') st.push(num);
                else if (sign == '-') st.push(-num);
                else if (sign == '*') st.push(st.pop() * num);
                else if (sign == '/') st.push(st.pop() / num);
                sign = c;
                num = 0;
            }
        }
        long sum = 0;
        for (long v : st) sum += v;
        return sum;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLine()) {
            System.out.println(calculate(scanner.nextLine()));
        }
    }
}