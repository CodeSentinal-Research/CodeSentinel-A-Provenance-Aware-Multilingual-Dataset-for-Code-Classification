import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine().replaceAll("\\s+", "");
        Stack<Long> vals = new Stack<>();
        Stack<Character> ops = new Stack<>();
        long num = 0, sign = 1;
        for(char c : s.toCharArray()) {
            if(Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if(c == '+' || c == '-') {
                vals.push(num * sign);
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if(c == '(') {
                ops.push((char)sign);
                ops.push('(');
                sign = 1;
            } else if(c == ')') {
                vals.push(num * sign);
                num = 0;
                long sum = 0;
                while(ops.peek() != '(') sum += vals.pop();
                ops.pop();
                sign = ops.pop();
                num = sum;
            }
        }
        vals.push(num * sign);
        long sum = 0;
        while(!vals.isEmpty()) sum += vals.pop();
        System.out.println(sum);
    }
}
