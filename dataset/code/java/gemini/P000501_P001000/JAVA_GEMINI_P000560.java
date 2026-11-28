import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] q = new int[n];
            for (int i = 0; i < n; i++) q[i] = scanner.nextInt();
            int half = n / 2;
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < half; i++) {
                sb.append(q[i]).append(" ").append(q[i + half]).append(i + 1 == half ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}