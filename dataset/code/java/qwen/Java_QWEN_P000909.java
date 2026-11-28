import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        
        long[][] C = new long[n+1][r+1];
        for(int i=0; i<=n; i++) {
            C[i][0] = 1;
            for(int j=1; j<=Math.min(i, r); j++) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
        System.out.println(C[n][r]);
    }
}
