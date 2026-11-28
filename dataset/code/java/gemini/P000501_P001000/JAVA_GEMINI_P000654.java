import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int pivot = vals[n - 1];
            StringBuilder sb = new StringBuilder();
            boolean first = true;
            for (int i = 0; i < n - 1; i++) {
                if (vals[i] < pivot) {
                    if (!first) sb.append(" ");
                    sb.append(vals[i]);
                    first = false;
                }
            }
            if (!first) sb.append(" ");
            sb.append(pivot);
            for (int i = 0; i < n - 1; i++) {
                if (vals[i] >= pivot) {
                    sb.append(" ").append(vals[i]);
                }
            }
            System.out.println(sb.toString());
        }
    }
}