import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int w = sc.nextInt(), h = sc.nextInt(), n = sc.nextInt();
            int[] xs = new int[n + 2];
            int[] ys = new int[n + 2];
            xs[0] = 0; xs[n + 1] = w + 1;
            ys[0] = 0; ys[n + 1] = h + 1;

            for (int i = 1; i <= n; i++) {
                xs[i] = sc.nextInt();
                ys[i] = sc.nextInt();
            }

            Arrays.sort(xs);
            Arrays.sort(ys);

            int maxDx = 0, maxDy = 0;
            for (int i = 1; i < xs.length; i++) {
                maxDx = Math.max(maxDx, xs[i] - xs[i - 1] - 1);
                maxDy = Math.max(maxDy, ys[i] - ys[i - 1] - 1);
            }
            System.out.println((long) maxDx * maxDy);
        }
        sc.close();
    }
}