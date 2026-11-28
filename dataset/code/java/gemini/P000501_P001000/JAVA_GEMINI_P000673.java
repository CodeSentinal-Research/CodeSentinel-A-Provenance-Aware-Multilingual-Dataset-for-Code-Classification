import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            if (n > 1) {
                StringBuilder sb = new StringBuilder();
                sb.append(vals[n - 1]);
                for (int i = 0; i < n - 1; i++) sb.append(" ").append(vals[i]);
                System.out.println(sb.toString());
            } else if (n == 1) {
                System.out.println(vals[0]);
            }
        }
    }
}