import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String path = scanner.next();
            String[] parts = path.split("/");
            Stack<String> st = new Stack<>();
            for (String p : parts) {
                if (p.isEmpty() || p.equals(".")) continue;
                if (p.equals("..")) {
                    if (!st.isEmpty()) st.pop();
                } else {
                    st.push(p);
                }
            }
            StringBuilder sb = new StringBuilder();
            for (String s : st) sb.append("/").append(s);
            System.out.println(sb.length() == 0 ? "/" : sb.toString());
        }
    }
}