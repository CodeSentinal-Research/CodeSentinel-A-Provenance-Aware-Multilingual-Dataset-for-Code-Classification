import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] t = new int[n], ans = new int[n];
            for (int i = 0; i < n; i++) t[i] = scanner.nextInt();
            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < n; i++) {
                while (!st.isEmpty() && t[st.peek()] < t[i]) {
                    int prev = st.pop();
                    ans[prev] = i - prev;
                }
                st.push(i);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(ans[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}