import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] p = new int[n], ans = new int[n];
            for (int i = 0; i < n; i++) { p[i] = scanner.nextInt(); ans[i] = p[i]; }
            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < n; i++) {
                while (!st.isEmpty() && p[st.peek()] >= p[i]) {
                    ans[st.pop()] -= p[i];
                }
                st.push(i);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(ans[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}