import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] a = new int[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) a[i][j] = sc.nextInt();
            
        // Transpose
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int t = a[i][j]; a[i][j] = a[j][i]; a[j][i] = t;
            }
        }
        // Reverse rows
        for(int i=0; i<n; i++) {
            for(int j=0; j<n/2; j++) {
                int t = a[i][j]; a[i][j] = a[i][n-1-j]; a[i][n-1-j] = t;
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) System.out.print(a[i][j] + " ");
            System.out.println();
        }
    }
}
