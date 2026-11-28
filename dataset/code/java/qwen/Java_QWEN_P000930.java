import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int p = sc.nextInt();
        int[][] a = new int[n][m];
        int[][] b = new int[m][p];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) a[i][j] = sc.nextInt();
        for(int i=0; i<m; i++)
            for(int j=0; j<p; j++) b[i][j] = sc.nextInt();
            
        int[][] res = new int[n][p];
        for(int i=0; i<n; i++) {
            for(int j=0; j<p; j++) {
                for(int k=0; k<m; k++) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<p; j++) System.out.print(res[i][j] + " ");
            System.out.println();
        }
    }
}
