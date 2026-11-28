import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[][] meetings = new int[n][2];
            for (int i = 0; i < n; i++) meetings[i][0] = sc.nextInt();
            for (int i = 0; i < n; i++) meetings[i][1] = sc.nextInt();

            Arrays.sort(meetings, (a, b) -> a[1] - b[1]);
            int count = 0, lastEnd = -1;

            for (int[] m : meetings) {
                if (m[0] > lastEnd) {
                    count++;
                    lastEnd = m[1];
                }
            }
            System.out.println(count);
        }
        sc.close();
    }
}