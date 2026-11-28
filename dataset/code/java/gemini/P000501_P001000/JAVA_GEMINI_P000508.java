import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] h = new int[n], ans = new int[n];
            for (int i = 0; i < n; i++) h[i] = scanner.nextInt();
            Stack<Integer> st = new Stack<>();
            // Process from right to left
            for (int i = n - 1; i >= 0; i--) {
                int count = 0;
                while (!st.isEmpty() && st.peek() < h[i]) {
                    st.pop();
                    count++;
                }
                if (!st.isEmpty()) count++;
                ans[i] = count;
                st.push(h[i]);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(ans[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}