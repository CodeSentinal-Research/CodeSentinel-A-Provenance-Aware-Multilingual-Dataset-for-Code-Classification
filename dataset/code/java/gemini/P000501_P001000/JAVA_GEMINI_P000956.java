import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Solution {
    private static long[] extGcd(long a, long b) {
        if (b == 0) return new long[]{a, 1, 0};
        long[] res = extGcd(b, a % b);
        long g = res[0], x1 = res[1], y1 = res[2];
        return new long[]{g, y1, x1 - (a / b) * y1};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            long m = sc.nextLong();
            long[] resGcd = extGcd(a, m);
            long g = resGcd[0], x = resGcd[1];
            if (b % g != 0) {
                System.out.println(-1);
            } else {
                long x0 = (x * (b / g)) % m;
                x0 = (x0 + m) % m;
                long step = m / g;
                List<Long> ans = new ArrayList<>();
                for (int i = 0; i < g; i++) {
                    ans.add((x0 + i * step) % m);
                }
                Collections.sort(ans);
                for (int i = 0; i < ans.size(); i++) {
                    System.out.print(ans.get(i) + (i == ans.size() - 1 ? "" : " "));
                }
                System.out.println();
            }
        }
        sc.close();
    }
}