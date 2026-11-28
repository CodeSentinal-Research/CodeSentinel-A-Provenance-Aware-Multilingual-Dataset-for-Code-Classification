import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            Stack<Character> st = new Stack<>();
            for (char c : s.toCharArray()) {
                if (c == ',' || c == '(') continue;
                if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                    st.push(c);
                } else if (c == ')') {
                    boolean seenT = false, seenF = false;
                    while (!st.isEmpty() && (st.peek() == 't' || st.peek() == 'f')) {
                        char val = st.pop();
                        if (val == 't') seenT = true;
                        if (val == 'f') seenF = true;
                    }
                    char op = st.pop();
                    if (op == '!') st.push(seenT ? 'f' : 't');
                    else if (op == '&') st.push(seenF ? 'f' : 't');
                    else if (op == '|') st.push(seenT ? 't' : 'f');
                }
            }
            System.out.println(st.peek() == 't' ? "true" : "false");
        }
    }
}