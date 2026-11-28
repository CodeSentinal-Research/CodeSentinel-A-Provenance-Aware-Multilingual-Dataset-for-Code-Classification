import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] keys = new int[n];
        int[] freqs = new int[n];
        for (int i = 0; i < n; i++) {
            keys[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            freqs[i] = scanner.nextInt();
        }

        System.out.println(optimalBST(keys, freqs, n));
    }

    static int optimalBST(int keys[], int freqs[], int n) {
        int cost[][] = new int[n+1][n+1];
        for (int i=0; i<n; i++)
            cost[i][i] = freqs[i];

        for (int L=2; L<=n; L++) {
            for (int i=0; i<=n-L+1; i++) {
                int j = i+L-1;
                cost[i][j] = Integer.MAX_VALUE;
                for (int r=i; r<=j; r++) {
                    int c = ((r > i)? cost[i][r-1]:0) +
                            ((r < j)? cost[r+1][j]:0) + freqs[r];
                    if (c < cost[i][j])
                        cost[i][j] = c;
               
               }
            }
        }
        return cost[0][n-1];
    }
}
