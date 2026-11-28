import java.util.*;
public class Main {
    static int n, count;
    static boolean[] cols, diag1, diag2;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        cols = new boolean[n];
        diag1 = new boolean[2*n];
        diag2 = new boolean[2*n];
        backtrack(0);
        System.out.println(count);
    }
    static void backtrack(int r) {
        if(r == n) {
            count++;
            return;
        }
        for(int c=0; c<n; c++) {
            if(cols[c] || diag1[r+c] || diag2[r-c+n]) continue;
            cols[c] = diag1[r+c] = diag2[r-c+n] = true;
            backtrack(r + 1);
            cols[c] = diag1[r+c] = diag2[r-c+n] = false;
        }
    }
}
