import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] a = new int[n][n];
        long trace = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                a[i][j] = sc.nextInt();
                if(i == j) trace += a[i][j];
            }
        }
        System.out.println(trace);
    }
}
