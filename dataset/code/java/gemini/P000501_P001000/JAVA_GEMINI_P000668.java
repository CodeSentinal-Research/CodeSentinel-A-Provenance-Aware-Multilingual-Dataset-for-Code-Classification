import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int size = scanner.nextInt();
            int[] vals = new int[size];
            for (int i = 0; i < size; i++) vals[i] = scanner.nextInt();
            int m = scanner.nextInt(), n = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            boolean first = true;
            int cur = 0;
            while (cur < size) {
                for (int i = 0; i < m && cur + i < size; i++) {
                    if (!first) sb.append(" ");
                    sb.append(vals[cur + i]);
                    first = false;
                }
                cur += m + n;
            }
            System.out.println(sb.toString());
        }
    }
}