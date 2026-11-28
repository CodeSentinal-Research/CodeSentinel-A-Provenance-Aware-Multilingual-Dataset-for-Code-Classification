import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            Stack<Integer> st = new Stack<>();
            for (int v : vals) {
                while (!st.isEmpty() && st.peek() < v) st.pop();
                st.push(v);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < st.size(); i++) {
                sb.append(st.get(i)).append(i + 1 == st.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}