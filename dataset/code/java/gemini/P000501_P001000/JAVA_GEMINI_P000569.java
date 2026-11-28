import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] q = new int[n];
            for (int i = 0; i < n; i++) q[i] = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            for (int i = n - 1; i >= 0; i--) sb.append(q[i]).append(i == 0 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}