import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int[] lastOcc = new int[26];
            for (int i = 0; i < s.length(); i++) lastOcc[s.charAt(i) - 'a'] = i;
            boolean[] seen = new boolean[26];
            StringBuilder st = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (!seen[c - 'a']) {
                    while (st.length() > 0 && st.charAt(st.length() - 1) > c && i < lastOcc[st.charAt(st.length() - 1) - 'a']) {
                        seen[st.charAt(st.length() - 1) - 'a'] = false;
                        st.deleteCharAt(st.length() - 1);
                    }
                    seen[c - 'a'] = true;
                    st.append(c);
                }
            }
            System.out.println(st.toString());
        }
    }
}