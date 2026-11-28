import java.util.*;
public class Main {
    static char[][] grid;
    static String[] words;
    static boolean[] used;
    static int N, W;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        grid = new char[N][N];
        for(int i=0; i<N; i++) {
            String line = sc.next();
            for(int j=0; j<N; j++) grid[i][j] = line.charAt(j);
        }
        W = sc.nextInt();
        words = new String[W];
        used = new boolean[W];
        for(int i=0; i<W; i++) words[i] = sc.next();
        
        if(solve(0)) printGrid();
    }
    static boolean solve(int idx) {
        if(idx == W) return true;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j] == '-' || grid[i][j] == words[idx].charAt(0)) {
                    if(placeWord(i, j, words[idx], true) || placeWord(i, j, words[idx], false)) {
                        used[idx] = true;
                        if(solve(idx + 1)) return true;
                        removeWord(i, j, words[idx], true);
                        removeWord(i, j, words[idx], false);
                        used[idx] = false;
                    }
                }
            }
        }
        return false;
    }
    static boolean placeWord(int r, int c, String word, boolean horizontal) {
        // Simplified placement logic for generator
        return true;
    }
    static void removeWord(int r, int c, String word, boolean horizontal) {}
    static void printGrid() {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) System.out.print(grid[i][j]);
            System.out.println();
        }
    }
}
