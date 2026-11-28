import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] inp = new int[n], out = new int[n];
            for (int i = 0; i < n; i++) inp[i] = scanner.nextInt();
            for (int i = 0; i < n; i++) out[i] = scanner.nextInt();
            Stack<Integer> st = new Stack<>();
            int j = 0;
            for (int x : inp) {
                st.push(x);
                while (!st.isEmpty() && j < n && st.peek() == out[j]) {
                    st.pop();
                    j++;
                }
            }
            System.out.println(j == n ? "true" : "false");
        }
    }
}