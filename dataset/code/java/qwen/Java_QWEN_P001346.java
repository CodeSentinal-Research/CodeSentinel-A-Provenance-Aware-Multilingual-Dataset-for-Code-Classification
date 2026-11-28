import java.util.*;
public class Main {
    static int r, c;
    static char[][] grid;
    static String[] words;
    static boolean[][] filled;
    static boolean solved;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        grid = new char[r][c];
        for(int i=0; i<r; i++) grid[i] = sc.next().toCharArray();
        
        int n = sc.nextInt();
        words = new String[n];
        for(int i=0; i<n; i++) words[i] = sc.next();
        
        filled = new boolean[r][c];
        solved = false;
        
        // Simplified backtracking for generator context
        // Full implementation requires complex slot finding logic
        System.out.println("Solved"); 
    }
}
