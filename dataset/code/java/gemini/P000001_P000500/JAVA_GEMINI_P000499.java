import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            StringBuilder st = new StringBuilder();
            for (char c : s.toCharArray()) {
                if (st.length() > 0 && Math.abs(st.charAt(st.length() - 1) - c) == 32) {
                    st.deleteCharAt(st.length() - 1);
                } else {
                    st.append(c);
                }
            }
            System.out.println(st.toString());
        }
    }
}