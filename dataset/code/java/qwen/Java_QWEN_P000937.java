import java.util.*;
public class Main {
    static final int MOD = 1000000007;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        long[][] a = new long[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) a[i][j] = sc.nextInt();
            
        long[][] res = matrixPow(a, k, n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) System.out.print(res[i][j] + " ");
            System.out.println();
        }
    }
    static long[][] matrixPow(long[][] base, long exp, int n) {
        long[][] res = new long[n][n];
        for(int i=0; i<n; i++) res[i][i] = 1;
        
        while(exp > 0) {
            if(exp % 2 == 1) res = multiply(res, base, n);
            base = multiply(base, base, n);
            exp /= 2;
        }
        return res;
    }
    static long[][] multiply(long[][] a, long[][] b, int n) {
        long[][] c = new long[n][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return c;
    }
}
