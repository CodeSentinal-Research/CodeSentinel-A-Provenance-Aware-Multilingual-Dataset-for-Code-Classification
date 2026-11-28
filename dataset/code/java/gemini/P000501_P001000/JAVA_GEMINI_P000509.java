import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            StringBuilder st = new StringBuilder();
            for (char c : s.toCharArray()) {
                if (Character.isDigit(c)) {
                    if (st.length() > 0) st.deleteCharAt(st.length() - 1);
                } else {
                    st.append(c);
                }
            }
            System.out.println(st.toString());
        }
    }
}