import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[][] jobs = new int[n][2];
            int maxD = 0;
            for (int i = 0; i < n; i++) {
                jobs[i][0] = sc.nextInt(); // deadline
                maxD = Math.max(maxD, jobs[i][0]);
            }
            for (int i = 0; i < n; i++) {
                jobs[i][1] = sc.nextInt(); // profit
            }

            Arrays.sort(jobs, (a, b) -> b[1] - a[1]);
            int[] slots = new int[maxD + 1];
            Arrays.fill(slots, -1);
            int count = 0, totalProfit = 0;

            for (int[] jb : jobs) {
                for (int j = jb[0]; j > 0; j--) {
                    if (slots[j] == -1) {
                        slots[j] = jb[1];
                        count++;
                        totalProfit += jb[1];
                        break;
                    }
                }
            }
            System.out.println(count + " " + totalProfit);
        }
        sc.close();
    }
}