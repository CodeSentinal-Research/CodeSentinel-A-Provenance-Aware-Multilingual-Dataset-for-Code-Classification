import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            Stack<Integer> st = new Stack<>();
            st.push(-1);
            int maxLen = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(') {
                    st.push(i);
                } else {
                    st.pop();
                    if (st.isEmpty()) {
                        st.push(i);
                    } else {
                        maxLen = Math.max(maxLen, i - st.peek());
                    }
                }
            }
            System.out.println(maxLen);
        }
    }
}