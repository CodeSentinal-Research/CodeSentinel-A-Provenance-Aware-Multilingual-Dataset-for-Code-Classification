import java.util.Scanner;

public class Main {
    static int[] inorder;
    static int[] minTree;
    static int[] sum;
    static int[][] dp;
    static int N;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        inorder = new int[N];
        minTree = new int[N];
        sum = new int[N];
        dp = new int[N][N];
        for (int i = 0; i < N; i++) {
            inorder[i] = sc.nextInt();
        }
        sc.close();
        System.out.println(getMinCost(0, N - 1));
    }

    static int getMinCost(int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == r) {
            return minTree[l] = inorder[l];
        }
        if (dp[l][r] != 0) {
            return dp[l][r];
        }
        int min = Integer.MAX_VALUE;
        for (int i = l; i <= r; i++) {
            int cost = inorder[i] * (minTree[l] * minTree[r]);
            if (cost < min) {
                min = cost;
            }
        }
        minTree[l] = minTree[r] = min;
        return dp[l][r] = min;
    }
}
