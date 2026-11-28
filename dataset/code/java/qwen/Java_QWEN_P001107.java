import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        boolean[][] reach = new boolean[n + 1][n + 1];
        for (int i = 1; i <= n; i++) reach[i][i] = true;
        
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            reach[u][v] = true;
        }
        
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (reach[i][k] && reach[k][j]) reach[i][j] = true;
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                System.out.print((reach[i][j] ? 1 : 0) + " ");
            }
            System.out.println();
        }
    }
}
