import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            Stack<StringBuilder> st = new Stack<>();
            st.push(new StringBuilder());
            for (char c : s.toCharArray()) {
                if (c == '(') {
                    st.push(new StringBuilder());
                } else if (c == ')') {
                    StringBuilder top = st.pop().reverse();
                    st.peek().append(top);
                } else {
                    st.peek().append(c);
                }
            }
            System.out.println(st.peek().toString());
        }
    }
}