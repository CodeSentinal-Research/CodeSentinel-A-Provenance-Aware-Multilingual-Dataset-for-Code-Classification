import java.util.*;
public class Main {
    static int n;
    static int[][] constraints;
    static int[][] grid;
    static boolean solved;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int m = sc.nextInt();
        grid = new int[n][n];
        constraints = new int[m][3];
        for(int i=0; i<m; i++) {
            constraints[i][0] = sc.nextInt();
            constraints[i][1] = sc.nextInt();
            constraints[i][2] = sc.nextInt();
        }
        
        solved = false;
        backtrack(0, 0);
        if(!solved) System.out.println("IMPOSSIBLE");
    }
    
    static void backtrack(int r, int c) {
        if(solved) return;
        if(r == n) {
            if(checkConstraints()) {
                solved = true;
                printGrid();
            }
            return;
        }
        
        int nextR = (c == n-1) ? r+1 : r;
        int nextC = (c == n-1) ? 0 : c+1;
        
        for(int val=1; val<=n*n; val++) {
            if(isValid(r, c, val)) {
                grid[r][c] = val;
                backtrack(nextR, nextC);
                grid[r][c] = 0;
            }
        }
    }
    
    static boolean isValid(int r, int c, int val) {
        // Check row/col uniqueness
        for(int i=0; i<n; i++) {
            if(grid[r][i] == val || grid[i][c] == val) return false;
        }
        return true;
    }
    
    static boolean checkConstraints() {
        // Implement constraint checking logic
        return true;
    }
    
    static void printGrid() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) System.out.print(grid[i][j] + " ");
            System.out.println();
        }
    }
}
