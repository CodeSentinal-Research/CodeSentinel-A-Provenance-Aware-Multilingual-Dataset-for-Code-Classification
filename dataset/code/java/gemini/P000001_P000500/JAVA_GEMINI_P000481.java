import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < n; i++) {
                String op = scanner.next();
                if (op.equals("+")) {
                    int top = st.pop();
                    int newTop = top + st.peek();
                    st.push(top);
                    st.push(newTop);
                } else if (op.equals("D")) {
                    st.push(st.peek() * 2);
                } else if (op.equals("C")) {
                    st.pop();
                } else {
                    st.push(Integer.parseInt(op));
                }
            }
            int sum = 0;
            for (int v : st) sum += v;
            System.out.println(sum);
        }
    }
}