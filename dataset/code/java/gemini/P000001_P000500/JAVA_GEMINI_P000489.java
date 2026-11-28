import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            Stack<Integer> st = new Stack<>(), minSt = new Stack<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("push")) {
                    int val = scanner.nextInt();
                    st.push(val);
                    minSt.push(minSt.isEmpty() ? val : Math.min(val, minSt.peek()));
                } else if (cmd.equals("pop")) {
                    if (!st.isEmpty()) { st.pop(); minSt.pop(); }
                } else if (cmd.equals("top")) {
                    if (!st.isEmpty()) System.out.println(st.peek());
                } else if (cmd.equals("getMin")) {
                    if (!minSt.isEmpty()) System.out.println(minSt.peek());
                }
            }
        }
    }
}