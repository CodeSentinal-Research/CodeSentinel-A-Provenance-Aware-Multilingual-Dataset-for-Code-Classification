import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] keys = new int[n];
        for (int i = 0; i < n; i++) {
            keys[i] = scanner.nextInt();
        }
        int[] successFreq = new int[n];
        for (int i = 0; i < n; i++) {
            successFreq[i] = scanner.nextInt();
        }
        int[] failFreq = new int[n];
        for (int i = 0; i < n; i++) {
            failFreq[i] = scanner.nextInt();
        }

        System.out.println(optimalBST(keys, successFreq, failFreq));
    }

    static int optimalBST(int[] keys, int[] successFreq, int[] failFreq) {
        int n = keys.length;
        int[][] cost = new int[n+1][n+1];
        int[][] sum = new int[n+1][n+1];

        for (int i = 0; i <= n; i++) {
            cost[i][i-1] = 0;
            sum[i][i-1] = 0;
        }

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n-len; i++) {
                int j = i + len - 1;
                cost[i][j] = Integer.MAX_VALUE;
                sum[i][j] = sum[i][j-1] + keys[j] + successFreq[j] - failFreq[j];
                for (int k = i; k <= j; k++) {
                    int c = ((k > i) ? cost[i][k-1] : 0) + ((k < j) ? cost[k+1][j] : 0);
                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                    }
                }
                cost[i][j] += sum[i][j];
            }
        }

        return cost[0][n-1];
    }
}
