import java.util.*;

public class Solution {
    public static int calculate(String s) {
        Deque<Integer> stack = new ArrayDeque<>();
        int res = 0, num = 0, sign = 1;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                stack.push(res);
                stack.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                int prevSign = stack.pop();
                int prevRes = stack.pop();
                res = prevRes + prevSign * res;
            }
        }
        res += sign * num;
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLine()) {
            System.out.println(calculate(scanner.nextLine()));
        }
    }
}