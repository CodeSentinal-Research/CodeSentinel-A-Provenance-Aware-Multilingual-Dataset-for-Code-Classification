import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int k = scanner.nextInt();
            int width = n / k, rem = n % k, cur = 0;
            for (int i = 0; i < k; i++) {
                int sz = width + (i < rem ? 1 : 0);
                if (sz == 0) {
                    System.out.println("[]");
                } else {
                    StringBuilder sb = new StringBuilder();
                    for (int j = 0; j < sz; j++) {
                        sb.append(vals[cur + j]).append(j + 1 == sz ? "" : " ");
                    }
                    System.out.println(sb.toString());
                    cur += sz;
                }
            }
        }
    }
}