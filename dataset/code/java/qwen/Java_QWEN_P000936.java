import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean sym = true;
        int[][] a = new int[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) a[i][j] = sc.nextInt();
            
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(a[i][j] != a[j][i]) sym = false;
            }
        }
        System.out.println(sym ? "true" : "false");
    }
}
