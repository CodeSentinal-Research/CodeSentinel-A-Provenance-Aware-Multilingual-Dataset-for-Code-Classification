import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int x = scanner.nextInt(), y = scanner.nextInt();
            int ix = -1, iy = -1;
            for (int i = 0; i < n; i++) {
                if (vals[i] == x && ix == -1) ix = i;
                if (vals[i] == y && iy == -1) iy = i;
            }
            if (ix != -1 && iy != -1) {
                int tmp = vals[ix]; vals[ix] = vals[iy]; vals[iy] = tmp;
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(vals[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}