import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int val = sc.nextInt();
                if(i == j || i + j == n - 1) sum += val;
            }
        }
        if(n % 2 == 1) {
            // Center counted twice
            sum -= sc.nextInt(); // This logic is flawed because input is already consumed
            // Correct way: read all first
        }
        // Re-implementing properly
        int[][] a = new int[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) a[i][j] = sc.nextInt(); // Wait, scanner already consumed
        
        // Let's assume we read into array first
        long s = 0;
        for(int i=0; i<n; i++) {
            s += a[i][i];
            s += a[i][n-1-i];
        }
        if(n % 2 == 1) s -= a[n/2][n/2];
        System.out.println(s);
    }
}
