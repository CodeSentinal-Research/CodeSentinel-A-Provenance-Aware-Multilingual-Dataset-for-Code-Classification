import java.util.*;
public class Solution {
    static int idx = 0;
    static long parse(String s) {
        Stack<Long> st = new Stack<>();
        long num = 0;
        char sign = '+';
        while (idx < s.length()) {
            char c = s.charAt(idx++);
            if (Character.isDigit(c)) num = num * 10 + (c - '0');
            if (c == '(') num = parse(s);
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == ')' || idx == s.length()) {
                if (sign == '+') st.push(num);
                else if (sign == '-') st.push(-num);
                else if (sign == '*') st.push(st.pop() * num);
                else if (sign == '/') st.push(st.pop() / num);
                if (c == ')') break;
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
            idx = 0;
            System.out.println(parse(scanner.nextLine()));
        }
    }
}