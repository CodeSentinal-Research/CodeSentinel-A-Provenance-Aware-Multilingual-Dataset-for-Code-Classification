import java.util.*;
public class Main {
    static int r, c;
    static char[][] grid;
    static String word;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        grid = new char[r][c];
        for(int i=0; i<r; i++) grid[i] = sc.next().toCharArray();
        word = sc.next();
        
        boolean found = false;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == word.charAt(0)) {
                    boolean[][] visited = new boolean[r][c];
                    if(dfs(i, j, 0, visited)) {
                        found = true;
                        break;
                    }
                }
            }
            if(found) break;
        }
        System.out.println(found ? "YES" : "NO");
    }
    
    static boolean dfs(int i, int j, int idx, boolean[][] visited) {
        if(idx == word.length()) return true;
        if(i < 0 || i >= r || j < 0 || j >= c || visited[i][j] || grid[i][j] != word.charAt(idx)) return false;
        
        visited[i][j] = true;
        if(dfs(i+1, j, idx+1, visited) || dfs(i-1, j, idx+1, visited) || 
           dfs(i, j+1, idx+1, visited) || dfs(i, j-1, idx+1, visited)) {
            return true;
        }
        visited[i][j] = false;
        return false;
    }
}
