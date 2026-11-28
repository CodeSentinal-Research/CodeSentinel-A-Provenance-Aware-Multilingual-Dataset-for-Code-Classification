import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextLong();
            long MOD = 1000000007;
            int[] prevLess = new int[n], nextLess = new int[n];
            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < n; i++) {
                while (!st.isEmpty() && arr[st.peek()] >= arr[i]) st.pop();
                prevLess[i] = st.isEmpty() ? -1 : st.peek();
                st.push(i);
            }
            st.clear();
            // Process from right to left
            for (int i = n - 1; i >= 0; i--) {
                while (!st.isEmpty() && arr[st.peek()] > arr[i]) st.pop();
                nextLess[i] = st.isEmpty() ? n : st.peek();
                st.push(i);
            }
            long ans = 0;
            for (int i = 0; i < n; i++) {
                long left = i - prevLess[i];
                long right = nextLess[i] - i;
                ans = (ans + arr[i] * left % MOD * right % MOD) % MOD;
            }
            System.out.println(ans);
        }
    }
}