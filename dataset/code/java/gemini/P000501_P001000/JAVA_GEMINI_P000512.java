import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] pushed = new int[n], popped = new int[n];
            for (int i = 0; i < n; i++) pushed[i] = scanner.nextInt();
            for (int i = 0; i < n; i++) popped[i] = scanner.nextInt();
            Stack<Integer> st = new Stack<>();
            int j = 0;
            for (int x : pushed) {
                st.push(x);
                while (!st.isEmpty() && j < n && st.peek() == popped[j]) {
                    st.pop();
                    j++;
                }
            }
            System.out.println(j == n ? "true" : "false");
        }
    }
}