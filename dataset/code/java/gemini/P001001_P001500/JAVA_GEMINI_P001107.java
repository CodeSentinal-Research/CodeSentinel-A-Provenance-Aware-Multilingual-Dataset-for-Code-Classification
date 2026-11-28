import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            int[][] reach = new int[n][n];
            for (int i = 0; i < n; i++) reach[i][i] = 1;
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                reach[u][v] = 1;
            }

            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (reach[i][k] == 1 && reach[k][j] == 1) {
                            reach[i][j] = 1;
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(reach[i][j] + (j == n - 1 ? "" : " "));
                }
                System.out.println();
            }
        }
        sc.close();
    }
}