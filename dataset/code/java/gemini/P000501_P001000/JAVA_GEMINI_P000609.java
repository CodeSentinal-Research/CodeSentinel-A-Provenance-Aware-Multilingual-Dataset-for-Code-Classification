import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<Integer> st = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int x = scanner.nextInt();
                st.add(x);
                int s = 0;
                for (int j = st.size() - 1; j >= 0; j--) {
                    s += st.get(j);
                    if (s == 0) {
                        while (st.size() > j) st.remove(st.size() - 1);
                        break;
                    }
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < st.size(); i++) {
                sb.append(st.get(i)).append(i + 1 == st.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}