import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            Stack<Integer> st = new Stack<>();
            st.push(0);
            for (char c : s.toCharArray()) {
                if (c == '(') {
                    st.push(0);
                } else {
                    int v = st.pop();
                    int top = st.pop();
                    st.push(top + Math.max(2 * v, 1));
                }
            }
            System.out.println(st.peek());
        }
    }
}