import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine().replaceAll("\\s+", "");
        int[] idx = {0};
        System.out.println(evaluate(s, idx));
    }
    static long evaluate(String s, int[] idx) {
        Stack<Long> stack = new Stack<>();
        char sign = '+';
        while(idx[0] < s.length()) {
            char c = s.charAt(idx[0]++);
            if(Character.isDigit(c)) {
                int num = 0;
                while(idx[0] < s.length() && Character.isDigit(s.charAt(idx[0]))) {
                    num = num * 10 + (s.charAt(idx[0]++) - '0');
                }
                if(sign == '+') stack.push((long)num);
                else if(sign == '-') stack.push((long)-num);
                else if(sign == '*') stack.push(stack.pop() * num);
                else if(sign == '/') stack.push(stack.pop() / num);
            } else if(c == '(') {
                long num = evaluate(s, idx);
                if(sign == '+') stack.push(num);
                else if(sign == '-') stack.push(-num);
                else if(sign == '*') stack.push(stack.pop() * num);
                else if(sign == '/') stack.push(stack.pop() / num);
            } else if(c == ')') {
                break;
            } else {
                sign = c;
            }
        }
        long sum = 0;
        for(long x : stack) sum += x;
        return sum;
    }
}
