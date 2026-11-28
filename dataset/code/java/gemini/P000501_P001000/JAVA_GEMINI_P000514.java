import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            Stack<Character> st = new Stack<>();
            for (int i = s.length() - 1; i >= 0; i--) {
                char c = s.charAt(i);
                if (!st.isEmpty() && st.peek() == '?') {
                    st.pop(); // '?'
                    char first = st.pop();
                    st.pop(); // ':'
                    char second = st.pop();
                    st.push(c == 'T' ? first : second);
                } else {
                    st.push(c);
                }
            }
            System.out.println(st.peek());
        }
    }
}