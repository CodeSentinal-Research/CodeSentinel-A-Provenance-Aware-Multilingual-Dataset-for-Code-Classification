import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Stack<Long> st = new Stack<>();
            for (int i = 0; i < n; i++) {
                String s = scanner.next();
                if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
                    long b = st.pop();
                    long a = st.pop();
                    if (s.equals("+")) st.push(a + b);
                    else if (s.equals("-")) st.push(a - b);
                    else if (s.equals("*")) st.push(a * b);
                    else if (s.equals("/")) st.push(a / b);
                } else {
                    st.push(Long.parseLong(s));
                }
            }
            System.out.println(st.peek());
        }
    }
}