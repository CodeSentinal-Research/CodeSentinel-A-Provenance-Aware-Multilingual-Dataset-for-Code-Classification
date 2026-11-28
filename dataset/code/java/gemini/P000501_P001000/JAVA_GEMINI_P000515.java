import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            double[][] cars = new double[n][2];
            for (int i = 0; i < n; i++) {
                cars[i][0] = scanner.nextDouble();
                cars[i][1] = scanner.nextDouble();
            }
            double[] ans = new double[n];
            Arrays.fill(ans, -1.0);
            Stack<Integer> st = new Stack<>();
            // Process from right to left
            for (int i = n - 1; i >= 0; i--) {
                while (!st.isEmpty()) {
                    int j = st.peek();
                    if (cars[i][1] <= cars[j][1] || (ans[j] > 0 && (cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1]) >= ans[j])) {
                        st.pop();
                    } else {
                        break;
                    }
                }
                if (!st.isEmpty()) {
                    int j = st.peek();
                    ans[i] = (cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1]);
                }
                st.push(i);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(String.format(Locale.US, "%.5f", ans[i])).append(i == n - 1 ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}