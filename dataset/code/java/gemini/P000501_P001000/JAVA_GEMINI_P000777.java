import java.util.*;
public class Solution {
    static boolean canPlaceH(int n, char[][] grid, int r, int c, String w) {
        if (c + w.length() > n) return false;
        for (int i = 0; i < w.length(); i++) {
            if (grid[r][c + i] != '-' && grid[r][c + i] != w.charAt(i)) return false;
        }
        return true;
    }
    static List<int[]> placeH(char[][] grid, int r, int c, String w) {
        List<int[]> placed = new ArrayList<>();
        for (int i = 0; i < w.length(); i++) {
            if (grid[r][c + i] == '-') {
                grid[r][c + i] = w.charAt(i);
                placed.add(new int[]{r, c + i});
            }
        }
        return placed;
    }
    static boolean canPlaceV(int n, char[][] grid, int r, int c, String w) {
        if (r + w.length() > n) return false;
        for (int i = 0; i < w.length(); i++) {
            if (grid[r + i][c] != '-' && grid[r + i][c] != w.charAt(i)) return false;
        }
        return true;
    }
    static List<int[]> placeV(char[][] grid, int r, int c, String w) {
        List<int[]> placed = new ArrayList<>();
        for (int i = 0; i < w.length(); i++) {
            if (grid[r + i][c] == '-') {
                grid[r + i][c] = w.charAt(i);
                placed.add(new int[]{r + i, c});
            }
        }
        return placed;
    }
    static void unplace(char[][] grid, List<int[]> placed) {
        for (int[] p : placed) grid[p[0]][p[1]] = '-';
    }
    static boolean backtrack(int n, char[][] grid, String[] words, int idx) {
        if (idx == words.length) return true;
        String w = words[idx];
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (canPlaceH(n, grid, r, c, w)) {
                    List<int[]> placed = placeH(grid, r, c, w);
                    if (backtrack(n, grid, words, idx + 1)) return true;
                    unplace(grid, placed);
                }
                if (canPlaceV(n, grid, r, c, w)) {
                    List<int[]> placed = placeV(grid, r, c, w);
                    if (backtrack(n, grid, words, idx + 1)) return true;
                    unplace(grid, placed);
                }
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            char[][] grid = new char[n][n];
            for (int i = 0; i < n; i++) grid[i] = scanner.next().toCharArray();
            int wCnt = scanner.nextInt();
            String[] words = new String[wCnt];
            for (int i = 0; i < wCnt; i++) words[i] = scanner.next();
            backtrack(n, grid, words, 0);
            for (int i = 0; i < n; i++) System.out.println(new String(grid[i]));
        }
    }
}