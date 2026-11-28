import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String num = scanner.next();
            int k = scanner.nextInt();
            StringBuilder st = new StringBuilder();
            for (char c : num.toCharArray()) {
                while (k > 0 && st.length() > 0 && st.charAt(st.length() - 1) > c) {
                    st.deleteCharAt(st.length() - 1);
                    k--;
                }
                st.append(c);
            }
            while (k > 0 && st.length() > 0) {
                st.deleteCharAt(st.length() - 1);
                k--;
            }
            int idx = 0;
            while (idx < st.length() && st.charAt(idx) == '0') idx++;
            String res = st.substring(idx);
            System.out.println(res.isEmpty() ? "0" : res);
        }
    }
}