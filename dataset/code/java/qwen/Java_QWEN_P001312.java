import java.util.*;
public class Main {
    static int n;
    static boolean[] cols;
    static boolean[] diag1;
    static boolean[] diag2;
    static int count;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        
        cols = new boolean[n];
        diag1 = new boolean[2*n];
        diag2 = new boolean[2*n];
        
        backtrack(0);
        System.out.println(count);
    }
    
    static void backtrack(int row) {
        if(row == n) {
            count++;
            return;
        }
        for(int col=0; col<n; col++) {
            if(cols[col] || diag1[row+col] || diag2[row-col+n]) continue;
            
            cols[col] = true;
            diag1[row+col] = true;
            diag2[row-col+n] = true;
            
            backtrack(row + 1);
            
            cols[col] = false;
            diag1[row+col] = false;
            diag2[row-col+n] = false;
        }
    }
}
