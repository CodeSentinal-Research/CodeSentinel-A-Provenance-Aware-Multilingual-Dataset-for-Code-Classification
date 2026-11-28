import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[][] acts = new int[n][2];
            for (int i = 0; i < n; i++) acts[i][0] = sc.nextInt();
            for (int i = 0; i < n; i++) acts[i][1] = sc.nextInt();

            Arrays.sort(acts, (a, b) -> a[1] - b[1]);
            int count = 0, lastEnd = -1;
            for (int[] act : acts) {
                if (act[0] >= lastEnd) {
                    count++;
                    lastEnd = act[1];
                }
            }
            System.out.println(count);
        }
        sc.close();
    }
}